#ifndef BATTLEFIELD_HPP
#define BATTLEFIELD_HPP 

#include <unistd.h>
#include <iostream>
#include <ncurses.h>
#include "Ship.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

int const yMap = 40;
int const xMap = 120;
int const maxNumberOfEnemies = 25;
int const maxNumberOfBullets = 5;

class Battlefield {
	public:
		Battlefield();
		~Battlefield();
		Battlefield(Battlefield const& cpy);

		void initializeMap();
		void mapToScreen();
		void playerInitalPosition(Ship& player);
		void nullEnemiesArray();
		void generateEnemy();
		void moveEnemies(Ship& player);
		void destroyEnemy();
		void nullBulletsArray();
		void generateBullet(Ship& player);
		void moveBullets();
		void destroyBullet();
		void keyPressAction(Ship& player);
		void removeDelay();
		void colorInitialization();
		void topAndBottomBorders(int y, int x, int limit);
		void leftAndRightBorders(int y, int x, int limit);

		int _map[yMap][xMap];
		Enemy* _enemies[maxNumberOfEnemies];
		Bullet* _bullets[maxNumberOfBullets];
		int _score;
		int _ammo;

		Battlefield& operator=(Battlefield const& rhs);
	protected:
	private:
};

#endif
