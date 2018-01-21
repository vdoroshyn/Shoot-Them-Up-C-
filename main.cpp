#include <iostream>
#include <ncurses.h>
#include "GameObject.hpp"
#include "Enemy.hpp"
#include "Ship.hpp"
#include "Battlefield.hpp"
#include <cstdlib>

int main() {
	std::srand(std::time(0));

	Battlefield screen;
	Ship player(1, 20, 1);
	
	screen._map[player.getY()][player.getX()] = 1;
	screen.topAndBottomBorders(0, 0, 122);
	screen.topAndBottomBorders(42, 0, 123);
	screen.leftAndRightBorders(0, 0, 42);
	screen.leftAndRightBorders(0, 122, 42);
	screen.mapToScreen();
	 //    move(5, 5);

	// std::string text = "Hello world!";
	// for(int i = 0; i < int(text.size()); i++) {
	//     addch(text[i]);
	//     addch(' ');
	// }
	while (player.isAlive()) {
		screen.keyPressAction(player);
		screen.generateEnemy();
		screen.moveBullets();
		screen.moveEnemies(player);
		screen.destroyEnemy();
		screen.destroyBullet();
		screen.mapToScreen();
		screen.removeDelay();
	}
	return 0;
}
