NAME = ft_retro
CC = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

OBJECTS = main.o \
			Ship.o \
			Enemy.o \
			Bullet.o \
			GameObject.o \
			Battlefield.o \

.PHONY : clean all fclean re

all : $(NAME)
	
$(NAME) : $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJECTS) -lncurses

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Ship.o : Ship.cpp
	$(CC) $(CPPFLAGS) -c Ship.cpp Ship.hpp

Enemy.o : Enemy.cpp
	$(CC) $(CPPFLAGS) -c Enemy.cpp Enemy.hpp

Bullet.o : Bullet.cpp
	$(CC) $(CPPFLAGS) -c Bullet.cpp Bullet.hpp

GameObject.o : GameObject.cpp
	$(CC) $(CPPFLAGS) -c GameObject.cpp GameObject.hpp

Battlefield.o : Battlefield.cpp
	$(CC) $(CPPFLAGS) -c Battlefield.cpp Battlefield.hpp
