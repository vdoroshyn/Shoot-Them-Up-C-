#include "Enemy.hpp"

Enemy::Enemy() {
}

Enemy::Enemy(int xPos, int yPox, int health) {
	this->_xPos = xPos;
	this->_yPos = yPox;
	this->_health = health;
}

Enemy::Enemy(Enemy const& src) : GameObject(src) {
}

Enemy::~Enemy() {
}

//methods

void Enemy::move() {
	this->_health -= 1;
}

//operators

Enemy& Enemy::operator=(Enemy const& rhs) {
	if (this != &rhs) {
		this->_xPos = rhs.getX();
		this->_yPos = rhs.getY();
		this->_health = rhs.getHP();
	}
	return *this;
}
