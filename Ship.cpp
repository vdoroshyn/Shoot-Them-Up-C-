#include "Ship.hpp"

Ship::Ship() {
}

Ship::Ship(int xPos, int yPox, int health) {
	this->_xPos = xPos;
	this->_yPos = yPox;
	this->_health = health;
}

Ship::Ship(Ship const& src) : GameObject(src) {
}

Ship::~Ship() {
}

//methods

void Ship::moveUpwards() {
	if (this->getY() == 0) {
		return;
	}
	this->setY(this->getY() - 1);
}

void Ship::moveLeft() {
	if (this->getX() == 1) {
		return;
	}
	this->setX(this->getX() - 1);
}

void Ship::moveDownwards() {
	if (this->getY() == 39) {
		return;
	}
	this->setY(this->getY() + 1);
}

void Ship::moveRight() {
	if (this->getX() == 110) {
		return;
	}
	this->setX(this->getX() + 1);
}

//operators

Ship& Ship::operator=(Ship const& rhs) {
	if (this != &rhs) {
		this->_xPos = rhs.getX();
		this->_yPos = rhs.getY();
		this->_health = rhs.getHP();
	}
	return *this;
}
