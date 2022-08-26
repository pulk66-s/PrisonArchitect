#ifndef __OBJECT_NAMESPACE_HPP__
    #define __OBJECT_NAMESPACE_HPP__

namespace PA::Object {
    class Map;
    class MapManager;
    class Grid;
    class Background;
    class TileManager;
    class PlayerInfo;
    namespace Tile {
        class ITile;
        class ATile;
        class Factory;
        class BrickWall;
    };
    namespace PNJ {
        class PnjManager;
        class Pnj;
        class Workman;
        namespace IA {
            class Ia;
            class Workman;
        }
    }
    namespace Room {
        class ARoom;
        class RoomManager;
        class Delivery;
    }
    namespace Menu {
        class PlayerInfo;
        class GameUI;
        class AIcon;
        class Room;
        class Staff;
        class Material;
    }
}

#endif