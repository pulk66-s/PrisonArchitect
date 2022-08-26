CC			= g++
INCLUDES	= -Isrc
DEBUG_FLAGS	= -g3 -fsanitize=address
CPPFLAGS	= -W -Wall -Wextra -lSDL2 -lSDL2_image -lSDL2_ttf $(INCLUDES) -O3

LIB_PATH	= src/Lib
GLOBAL_PATH	= src/Global
OBJECT_PATH	= src/Object
SRC			= src/main.cpp \
			$(LIB_PATH)/SDL2/SDL2.cpp \
			$(LIB_PATH)/SDL2/Window.cpp \
			$(LIB_PATH)/SDL2/Renderer.cpp \
			$(LIB_PATH)/SDL2/Event.cpp \
			$(LIB_PATH)/SDL2/Image.cpp \
			$(LIB_PATH)/SDL2/Text.cpp \
			$(LIB_PATH)/SDL2/Camera.cpp \
			$(LIB_PATH)/SDL2/SpriteManager.cpp \
			$(LIB_PATH)/SDL2/Shape/Rectangle.cpp \
			$(GLOBAL_PATH)/Error/AError.cpp \
			$(GLOBAL_PATH)/Error/InvalidArgument.cpp \
			$(GLOBAL_PATH)/Error/BadInstance.cpp \
			$(OBJECT_PATH)/Map/Map.cpp \
			$(OBJECT_PATH)/Map/Grid.cpp \
			$(OBJECT_PATH)/Map/Background.cpp \
			$(OBJECT_PATH)/Map/TileManager.cpp \
			$(OBJECT_PATH)/PNJ/Pnj.cpp \
			$(OBJECT_PATH)/PNJ/PnjManager.cpp \
			$(OBJECT_PATH)/PNJ/Workman.cpp \
			$(OBJECT_PATH)/PNJ/IA/Ia.cpp \
			$(OBJECT_PATH)/PNJ/IA/Workman.cpp \
			$(OBJECT_PATH)/Room/ARoom.cpp \
			$(OBJECT_PATH)/Room/RoomManager.cpp \
			$(OBJECT_PATH)/Room/Delivery.cpp \
			$(OBJECT_PATH)/Menu/GameUI.cpp \
			$(OBJECT_PATH)/Menu/AIcon.cpp \
			$(OBJECT_PATH)/Menu/Room.cpp \
			$(OBJECT_PATH)/Menu/Staff.cpp \
			$(OBJECT_PATH)/Menu/Material.cpp \
			$(OBJECT_PATH)/Tile/ATile.cpp \
			$(OBJECT_PATH)/Tile/BrickWall.cpp \
			$(OBJECT_PATH)/Tile/TileFactory.cpp \

OBJ			= $(SRC:.cpp=.o)
NAME		= kittenArchitect

all: $(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
