#ifndef __GLOBAL_VECTOR_HPP__
    #define __GLOBAL_VECTOR_HPP__

    #include "GlobalNamespace.hpp"
    #include <ostream>

struct KA::Vector2i {
    int x;
    int y;

    KA::Vector2i operator+(const KA::Vector2i &other) const {
        return (KA::Vector2i{this->x + other.x, this->y + other.y});
    }

    KA::Vector2i operator-(const KA::Vector2i &other) const {
        return (KA::Vector2i{this->x - other.x, this->y - other.y});
    }

    KA::Vector2i operator+= (const KA::Vector2i &other) {
        this->x += other.x;
        this->y += other.y;
        return (*this);
    }

    KA::Vector2i operator-= (const KA::Vector2i &other) {
        this->x -= other.x;
        this->y -= other.y;
        return (*this);
    }

    KA::Vector2i operator/ (const int &other) {
        return (KA::Vector2i{this->x / other, this->y / other});
    }

    bool operator==(const KA::Vector2i &other) const {
        return (this->x == other.x && this->y == other.y);
    }

    bool operator<(const KA::Vector2i &other) const {
        return (this->x < other.x || (this->x == other.x && this->y < other.y));
    }

    friend std::ostream &operator<<(std::ostream &os, const KA::Vector2i &vector) {
        os << "(" << vector.x << ", " << vector.y << ")";
        return (os);
    }
};

#endif