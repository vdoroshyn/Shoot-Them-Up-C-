#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "GameObject.hpp"

class Enemy : public GameObject {
	public:
		Enemy();
		Enemy(int xPos, int yPox, int health);
		Enemy(Enemy const& src);
		~Enemy();
		
		Enemy& operator=(Enemy const& rhs);
	protected:
	private:
};

#endif
