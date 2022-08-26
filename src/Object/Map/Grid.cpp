#include "Grid.hpp"

namespace KA::Object {
    
    Grid::Grid()
    {
        this->squareDim = {30, 30};
        this->width = 100;
        this->height = 100;
        for (int i = 0; i < this->height; i++) {
            for (int j = 0; j < this->width; j++) {
                this->rectangles.push_back(KA::Lib::SDL2::Shape::Rectangle(
                    {j * this->squareDim.x, i * this->squareDim.y}, this->squareDim,
                    {150, 150, 150, 0}, false
                ));
            }
        }
        this->camera = KA::Lib::SDL2::Camera::getInstance();
        this->event = KA::Lib::SDL2::Event::getInstance();
        this->allowedWalls = {
            "brickWall",
        };
        this->images = {
            {
                "brickWall", std::make_shared<KA::Lib::SDL2::Image>(
                    "res/sprites/game/walls.png",
                    this->squareDim, KA::Vector2i{0, 0},
                    true, KA::Vector2i{32, 32}, KA::Lib::SDL2::Camera::Status::FIXED
                )
            },
        };
        this->images["brickWall"]->setIndex({8, 10});
        this->imageIndex = {
            {
                "brickWall", {
                    {UP, {9, 8}},
                    {DOWN, {9, 8}},
                    {LEFT, {8, 8}},
                    {RIGHT, {8, 8}},
                    {TOP_LEFT, {10, 8}},
                    {TOP_RIGHT, {11, 8}},
                    {BOTTOM_LEFT, {10, 9}},
                    {BOTTOM_RIGHT, {11, 9}},
                    {SINGLE_UP, {8, 9}},
                    {SINGLE_DOWN, {8, 10}},
                    {SINGLE_LEFT, {9, 9}},
                    {SINGLE_RIGHT, {9, 10}},
                }
            },
        };
        this->wallActions = {
            {"brickWall", CREATE_BRICK_WALL},
        };
    }

    void Grid::addWallToPreview(KA::Vector2i pos) {
        if (std::find_if(this->wallPreviews.begin(), this->wallPreviews.end(), [&](std::shared_ptr<KA::Lib::SDL2::Image> img) {
            return (img->getPosition().x == pos.x && img->getPosition().y == pos.y);
        }) == this->wallPreviews.end()) {
            std::shared_ptr<KA::Lib::SDL2::Image> wall = std::make_shared<KA::Lib::SDL2::Image>(*this->wallImage);
            wall->setPosition(pos);
            wall->setStatus(KA::Lib::SDL2::Camera::Status::MOVABLE);
            this->wallPreviews.push_back(wall);
        }
    }

    void Grid::setWallIndex(std::shared_ptr<KA::Lib::SDL2::Image> &wall, KA::Vector2i starting, KA::Vector2i ending) {
        KA::Vector2i pos = wall->getPosition();
        if (pos.x == starting.x && pos.x == ending.x && pos.y == starting.y && pos.y == ending.y) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::SINGLE_LEFT]);
        } else if (pos.x == starting.x && pos.x == ending.x && pos.y == starting.y) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::SINGLE_UP]);
        } else if (pos.x == starting.x && pos.x == ending.x && pos.y == ending.y) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::SINGLE_DOWN]);                        
        } else if (pos.y == starting.y && pos.y == ending.y && pos.x == starting.x) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::SINGLE_LEFT]);
        } else if (pos.y == starting.y && pos.y == ending.y && pos.x == ending.x) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::SINGLE_RIGHT]);
        } else if (pos.x == ending.x && pos.y == ending.y) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::BOTTOM_RIGHT]);
        } else if (pos.x == ending.x && pos.y == starting.y) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::TOP_RIGHT]);
        } else if (pos.x == starting.x && pos.y == ending.y) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::BOTTOM_LEFT]);
        } else if (pos.x == starting.x && pos.y == starting.y) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::TOP_LEFT]);
        } else if (pos.x == starting.x) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::LEFT]);
        } else if (pos.x == ending.x) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::RIGHT]);
        } else if (pos.y == starting.y) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::UP]);
        } else if (pos.y == ending.y) {
            wall->setIndex(this->imageIndex[this->wallCreationName][WallDirection::DOWN]);
        }
    }

    Grid::Action Grid::wallCreationUpdate() {
        KA::Vector2i mousePos = this->event->getMousePosition();
        KA::Vector2i mousePosGrid = this->transformPos(mousePos);
        KA::Vector2i camPos = this->camera->getPos();
        if (this->event->isRightClick()) {
            this->firstWallPos = nullptr;
            this->wallCreation = false;
            this->wallPreviews = {};
            this->wallCreationName = "";
            this->wallImage = nullptr;
            return (NONE);
        }
        if (this->firstWallPos != nullptr) {
            if (this->event->isRelease()) {
                for (std::shared_ptr<KA::Lib::SDL2::Image> wall : this->wallPreviews) {
                    this->wallInfos.push_back({
                        wall->getPosition(),
                        wall->getIndex()
                    });
                }
                this->createWall(this->wallCreationName);
                return (this->wallActions[this->wallCreationName]);
            } else {
                KA::Vector2i starting = *this->firstWallPos, ending = (mousePosGrid + camPos);
                KA::Vector2i diff = ending - starting;
                if (diff.x < 0) {
                    int temp = starting.x;
                    starting.x = ending.x;
                    ending.x = temp;
                }
                if (diff.y < 0) {
                    int temp = starting.y;
                    starting.y = ending.y;
                    ending.y = temp;
                }
                for (int i = starting.x; i <= ending.x; i += squareDim.x) {
                    KA::Vector2i pos = {i, starting.y};
                    this->addWallToPreview(pos);
                    pos = {i, ending.y};
                    this->addWallToPreview(pos);
                }
                for (int i = starting.y; i <= ending.y; i += squareDim.y) {
                    KA::Vector2i pos = {starting.x, i};
                    this->addWallToPreview(pos);
                    pos = {ending.x, i};
                    this->addWallToPreview(pos);
                }
                auto condition = std::remove_if(this->wallPreviews.begin(), this->wallPreviews.end(), [&](std::shared_ptr<KA::Lib::SDL2::Image> img) {
                    KA::Vector2i imgPos = img-> getPosition();
                    return ((imgPos.x != starting.x && imgPos.y != starting.y && imgPos.x != ending.x && imgPos.y != ending.y) || (imgPos.x < starting.x || imgPos.y < starting.y || imgPos.x > ending.x || imgPos.y > ending.y));
                });
                this->wallPreviews.erase(condition, this->wallPreviews.end());
                for (std::shared_ptr<KA::Lib::SDL2::Image> &wall : this->wallPreviews) {
                    this->setWallIndex(wall, starting, ending);
                }
            }
        } else {
            this->wallPreviews[0]->setPosition(mousePosGrid);
            if (this->event->isClick()) {
                KA::Vector2i rectPos = mousePosGrid + camPos;
                this->wallPreviews[0]->setPosition(rectPos);
                this->wallPreviews[0]->setStatus(KA::Lib::SDL2::Camera::Status::MOVABLE);
                this->firstWallPos = std::make_unique<KA::Vector2i>(rectPos);
            }
        }
        return (NONE);
    }

    Grid::Action Grid::update()
    {
        if (this->waitForRelease) {
            if (this->event->isRelease()) {
                this->waitForRelease = false;
            } else {
                return (NONE);
            }
        }
        if (this->wallCreation) {
            Action wallCreationAction = this->wallCreationUpdate();
            if (wallCreationAction != NONE)
                return (wallCreationAction);
        }
        return (NONE);
    }

    void Grid::createWall(std::string type) {
        if (std::find(this->allowedWalls.begin(), this->allowedWalls.end(), type) == this->allowedWalls.end()) {
            throw KA::Error::InvalidArgument("type is not allowed", "Grid::createWall");
        }
        this->wallCreation = true;
        this->firstWallPos = nullptr;
        this->wallCreationName = type;
        this->wallImage = this->images[type];
        this->wallPreviews = {};
        this->waitForRelease = true;
        this->wallPreviews.push_back(std::make_shared<KA::Lib::SDL2::Image>(*this->wallImage));
    }

    void Grid::draw()
    {
        for (std::size_t i = 0; i < this->rectangles.size(); i++) {
            this->rectangles[i].draw();
        }
        if (this->wallCreation) {
            for (std::shared_ptr<KA::Lib::SDL2::Image> wallPreview : this->wallPreviews) {
                wallPreview->draw();
            }
        }
    }

    KA::Vector2i Grid::getDim()
    {
        return (this->squareDim);
    }

    // C'EST PARFAIT ON NE TOUCHE PAS !!!!
    KA::Vector2i Grid::transformPos(KA::Vector2i pos)
    {
        KA::Vector2i camPos = this->camera->getPos();
        KA::Vector2i mousePos = this->event->getMousePosition();
        KA::Vector2i finalPos {
            pos.x - pos.x % this->squareDim.x,
            pos.y - pos.y % this->squareDim.y
        };
        finalPos.x -= camPos.x % this->squareDim.x;
        finalPos.y -= camPos.y % this->squareDim.y;
        if (mousePos.x % this->squareDim.x > this->squareDim.x - camPos.x % this->squareDim.x) {
            finalPos.x += this->squareDim.x;
        }
        if (mousePos.y % this->squareDim.y > this->squareDim.y - camPos.y % this->squareDim.y) {
            finalPos.y += this->squareDim.y;
        }
        return (finalPos);
    }

    std::vector<Grid::WallInfo> Grid::getWallsInfo()
    {
        std::vector<Grid::WallInfo> temp = this->wallInfos;
        this->wallInfos = {};
        return (temp);
    }

    std::shared_ptr<Grid> Grid::getInstance() {
        static std::shared_ptr<Grid> instance = std::make_shared<Grid>();
        return (instance);
    }

}