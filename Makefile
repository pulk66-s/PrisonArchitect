CC			= g++
INCLUDES	= -Isrc
DEBUG_FLAGS	= -g3 -fsanitize=address
CPPFLAGS	= -W -Wall -Wextra -lSDL2 -lSDL2_image -lSDL2_ttf $(INCLUDES) -O3 $(DEBUG_FLAGS)

LIB_PATH	= src/Lib
GLOBAL_PATH	= src/Global
OBJECT_PATH	= src/Object
SRC			= src/main.cpp \
			$(LIB_PATH)/SDL2/SDL2.cpp \
			$(LIB_PATH)/SDL2/Window.cpp \
			$(LIB_PATH)/SDL2/Renderer.cpp \
			$(LIB_PATH)/SDL2/Event.cpp \
			$(LIB_PATH)/SDL2/Camera.cpp \
			$(LIB_PATH)/SDL2/Graphic/Image.cpp \
			$(LIB_PATH)/SDL2/Graphic/SpriteSheet.cpp \
			$(LIB_PATH)/SDL2/Graphic/Text.cpp \
			$(LIB_PATH)/SDL2/Graphic/Texture.cpp \
			$(LIB_PATH)/SDL2/Graphic/SpriteManager.cpp \
			$(LIB_PATH)/SDL2/Graphic/Surface.cpp \
			$(LIB_PATH)/SDL2/Shape/Rectangle.cpp \
			$(GLOBAL_PATH)/Error/AError.cpp \
			$(GLOBAL_PATH)/Error/InvalidArgument.cpp \
			$(GLOBAL_PATH)/Error/BadInstance.cpp \
			$(GLOBAL_PATH)/Error/NotEnoughMoney.cpp \
			$(GLOBAL_PATH)/Error/NotifSuccess.cpp \
			$(OBJECT_PATH)/PlayerInfo.cpp \
			$(OBJECT_PATH)/Map/Map.cpp \
			$(OBJECT_PATH)/Map/Grid.cpp \
			$(OBJECT_PATH)/Map/Background.cpp \
			$(OBJECT_PATH)/PNJ/Pnj.cpp \
			$(OBJECT_PATH)/PNJ/PnjManager.cpp \
			$(OBJECT_PATH)/PNJ/Workman.cpp \
			$(OBJECT_PATH)/PNJ/Factory.cpp \
			$(OBJECT_PATH)/PNJ/IA/Ia.cpp \
			$(OBJECT_PATH)/PNJ/IA/Workman.cpp \
			$(OBJECT_PATH)/PNJ/Tasks/ATask.cpp \
			$(OBJECT_PATH)/PNJ/Tasks/TaskManager.cpp \
			$(OBJECT_PATH)/PNJ/Tasks/TaskRepartiter.cpp \
			$(OBJECT_PATH)/PNJ/Tasks/Factory.cpp \
			$(OBJECT_PATH)/PNJ/Tasks/WallTask.cpp \
			$(OBJECT_PATH)/Menu/GameUI.cpp \
			$(OBJECT_PATH)/Menu/AIcon.cpp \
			$(OBJECT_PATH)/Menu/Room.cpp \
			$(OBJECT_PATH)/Menu/Staff.cpp \
			$(OBJECT_PATH)/Menu/Material.cpp \
			$(OBJECT_PATH)/Menu/Player/PlayerInfo.cpp \
			$(OBJECT_PATH)/Menu/Player/PlayerMoney.cpp \
			$(OBJECT_PATH)/Menu/Player/PlayerMoneyIncome.cpp \
			$(OBJECT_PATH)/Menu/Notif/Notifs.cpp \
			$(OBJECT_PATH)/Menu/Notif/Error.cpp \
			$(OBJECT_PATH)/Menu/Notif/Success.cpp \
			$(OBJECT_PATH)/Menu/Notif/ANotif.cpp \
			$(OBJECT_PATH)/Tile/Room/ARoom.cpp \
			$(OBJECT_PATH)/Tile/Room/Manager.cpp \
			$(OBJECT_PATH)/Tile/Room/Delivery.cpp \
			$(OBJECT_PATH)/Tile/TileManager.cpp \
			$(OBJECT_PATH)/Tile/ATile.cpp \
			$(OBJECT_PATH)/Tile/Wall/Brick.cpp \
			$(OBJECT_PATH)/Tile/Wall/Manager.cpp \
			$(OBJECT_PATH)/Tile/Wall/AWall.cpp \
			$(OBJECT_PATH)/Tile/Factory.cpp \
			$(OBJECT_PATH)/Items/Factory.cpp \
			$(OBJECT_PATH)/Items/AItem.cpp \
			$(OBJECT_PATH)/Items/ItemManager.cpp \
			$(OBJECT_PATH)/Items/Brick.cpp \

OBJ			= $(SRC:.cpp=.o)
NAME		= prisonArchitect

all: $(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
