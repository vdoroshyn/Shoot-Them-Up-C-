#include <iostream>
#include <ncurses.h>
#include "GameObject.hpp"
#include "Enemy.hpp"
#include "Ship.hpp"
#include "Battlefield.hpp"
#include <cstdlib>

int main() {

	Battlefield screen;
	Ship player(1, 20, 1);

	screen._map[player.getY()][player.getX()] = 1;
	// screen._map[20][119] = 2;
	std::srand(std::time(0));
	screen._map[20][5] = 3;
	// std::cout << player->getX() << std::endl;
	// std::cout << player->getY() << std::endl;
	// std::cout << player->getHP() << std::endl;



	screen.topAndBottomBorders(0, 0, 122);
	screen.topAndBottomBorders(42, 0, 123);
	screen.leftAndRightBorders(0, 0, 42);
	screen.leftAndRightBorders(0, 122, 42);

	// attron(COLOR_PAIR(3));
	// mvprintw(20, 3, ">");
	// attroff(COLOR_PAIR(3));

	// attron(COLOR_PAIR(2));
	// mvprintw(20, 119, "|");
	// attroff(COLOR_PAIR(2));

	// attron(COLOR_PAIR(4));
	// mvprintw(20, 5, "-");
	// attroff(COLOR_PAIR(4));
	screen.mapToScreen();
 //    move(5, 5);

	// std::string text = "Hello world!";
	// for(int i = 0; i < int(text.size()); i++) {
	//     addch(text[i]);
	//     addch(' ');
	// }
	while (1) {
	screen.keyPressAction(player);
	screen.generateEnemy();
	screen.moveEnemies();
	screen.destroyEnemy();
	screen.mapToScreen();
	nodelay(stdscr, TRUE);
	double period = (1.0 / 20.0);
	usleep(period * 1000000.0);
	
}
    // while(1);


	return 0;
}
