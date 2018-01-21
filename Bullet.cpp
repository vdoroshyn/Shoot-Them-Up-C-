#include "Bullet.hpp"

Bullet::Bullet() {
}

Bullet::Bullet(int xPos, int yPox, int health) {
	this->_xPos = xPos;
	this->_yPos = yPox;
	this->_health = health;
}

Bullet::Bullet(Bullet const& src) : GameObject(src) {
}

Bullet::~Bullet() {
}

//operators

Bullet& Bullet::operator=(Bullet const& rhs) {
	if (this != &rhs) {
		this->_xPos = rhs.getX();
		this->_yPos = rhs.getY();
		this->_health = rhs.getHP();
	}
	return *this;
}
