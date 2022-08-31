#ifndef __OBJECT_NAMESPACE_HPP__
    #define __OBJECT_NAMESPACE_HPP__

namespace PA::Object {
    namespace Map {
        class Map;
        class Grid;
        class Background;
    }
    class PlayerInfo;
    namespace Tile {
        class TileManager;
        class Tiles;
        class ITile;
        class ATile;
        class Factory;
        namespace Wall {
            class Manager;
            class AWall;
            class Brick;
            class Preview;
        }
        namespace Room {
            class ARoom;
            class Manager;
            class Delivery;
        }
    };
    namespace PNJ {
        class PnjManager;
        class IPnj;
        class Pnj;
        class Pnjs;
        class Workman;
        class Factory;
        namespace IA {
            class Ia;
            class Workman;
        }
        namespace Task {
            class ITask;
            class ATask;
            class Tasks;
            class Manager;
            class Factory;
            class WallTask;
        };
    }
    namespace Menu {
        namespace Player {
            class PlayerInfo;
            class PlayerMoney;
            class PlayerMoneyIncome;
        }
        class GameUI;
        class AIcon;
        class Room;
        class Staff;
        class Material;
        namespace Notif {
            class ANotif;
            class Notifs;
            class Error;
            class Success;
        }
    }
    namespace Item {
        class ItemManager;
        class Factory;
        class AItem;
        class Items;
        class Brick;
    }
}

#endif