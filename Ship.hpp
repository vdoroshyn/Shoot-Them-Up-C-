#ifndef SHIP_HPP
#define SHIP_HPP

#include "GameObject.hpp"
#include <iostream>

class Ship : public GameObject {
	public:
		Ship();
		Ship(int xPos, int yPox, int health);
		Ship(Ship const& src);
		~Ship();

		void moveUpwards();
		void moveLeft();
		void moveDownwards();
		void moveRight();
		// void shoot();

		Ship& operator=(Ship const& rhs);
	protected:
	private:
};

#endif
