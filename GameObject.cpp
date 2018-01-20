#include "GameObject.hpp"

GameObject::GameObject() {
}

GameObject::GameObject(int xPos, int yPos, int health) : _xPos(xPos), _yPos(yPos), _health(health) {
}

GameObject::GameObject(GameObject const& src) {
	*this = src;
}

GameObject::~GameObject() {
}

//getters

int GameObject::getX() const {
	return this->_xPos;
}

int GameObject::getY() const {
	return this->_yPos;
}

int GameObject::getHP() const {
	return this->_health;
}

//setters

void GameObject::setX(int x) {
	this->_xPos = x;
}

void GameObject::setY(int y) {
	this->_yPos = y;
}

void GameObject::setHP(int health) {
	this->_health = health;
}

//methods

bool GameObject::isDead() {
	if (this->getHP() == 0) {
		return 1;
	}
	return 0;
}

//operators

GameObject& GameObject::operator=(GameObject const& rhs) {
	if (this != &rhs) {
		this->_xPos = rhs.getX();
		this->_yPos = rhs.getY();
		this->_health = rhs.getHP();
	}
	return *this;
}
