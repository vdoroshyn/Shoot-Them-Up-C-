#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "GameObject.hpp"

class Enemy : public GameObject {
	public:
		Enemy();
		Enemy(int xPos, int yPox, int health);
		Enemy(Enemy const& src);
		~Enemy();

		void move();

		Enemy& operator=(Enemy const& rhs);
	protected:
	private:
};

#endif
