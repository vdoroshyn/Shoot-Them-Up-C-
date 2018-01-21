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

	screen.mapToScreen();
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
