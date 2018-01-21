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
