#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include <string>

class GameObject {
	public:
		GameObject();
		GameObject(int xPos, int yPox, int health);
		GameObject(GameObject const& src);
		virtual ~GameObject();

		int getX() const;
		int getY() const;
		int getHP() const;

		void setX(int x);
		void setY(int y);
		void setHP(int health);

		bool isAlive();

		GameObject& operator=(GameObject const& rhs);
	protected:
		int _xPos;
		int _yPos;
		int _health;
	private:
};

#endif

// void Battlefield::moveBullets() {
// 	for (int i = 0; i < maxNumberOfBullets; ++i) {
// 		if (this->_bullets[i] != NULL) {
// 			if (this->_map[this->_bullets[i]->getY()][this->_bullets[i]->getX() + 1] == 2) {
// 				this->_map[this->_bullets[i]->getY()][this->_bullets[i]->getX()] = 0;
// 				delete this->_bullets[i];
// 				this->_bullets[i] = NULL;
// 				return;
// 			}
// 			this->_map[this->_bullets[i]->getY()][this->_bullets[i]->getX()] = 0;
// 			this->_bullets[i]->setX(this->_bullets[i]->getX() + 1);
// 			this->_map[this->_bullets[i]->getY()][this->_bullets[i]->getX()] = 3;
// 		}
// 	}
// }
