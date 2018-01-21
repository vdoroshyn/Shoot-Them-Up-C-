#ifndef BULLET_HPP
#define BULLET_HPP

#include "GameObject.hpp"

class Bullet : public GameObject {
	public:
		Bullet();
		Bullet(int xPos, int yPox, int health);
		Bullet(Bullet const& src);
		~Bullet();

		Bullet& operator=(Bullet const& rhs);
	protected:
	private:
};

#endif
