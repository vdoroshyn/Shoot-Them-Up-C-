#include "Battlefield.hpp"

Battlefield::Battlefield() {
	nullEnemiesArray();
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	colorInitialization();
	clear();
	refresh();
	initializeMap();
}

Battlefield::Battlefield(Battlefield const& src) {
	*this = src;
}

Battlefield::~Battlefield() {
}

//methods

void Battlefield::initializeMap() {
	for (int i = 0; i < yMap; ++i) {
        for (int j = 0; j < xMap; ++j) {
            this->_map[i][j] = 0;
        }
    }
}

void Battlefield::mapToScreen()
{
	int i = 0;
	int y = 1;

	while (i < yMap) {
		int j = 0;
		int x = 1;

		while (j < xMap) {
			int cell = this->_map[i][j];
			if (cell == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(y, x, ">");
				attroff(COLOR_PAIR(3));		
			} else if (cell == 2) {
				attron(COLOR_PAIR(2));
				mvprintw(y, x, "|");
				attroff(COLOR_PAIR(2));
			} else if (cell == 3) {
				attron(COLOR_PAIR(4));
				mvprintw(y, x, "-");
				attroff(COLOR_PAIR(4));
			} else {
				attron(COLOR_PAIR(33));
				mvprintw(y, x, " ");
				attroff(COLOR_PAIR(33));
			}
			++j;
			++x;
		}
		++i;
		++y;
	}
	refresh();
}


void Battlefield::nullEnemiesArray() {
	for (int i = 0; i < maxNumberOfEnemies; ++i) {
		this->_enemies[i] = NULL;
	}
}

void Battlefield::generateEnemy() {
	for (int i = 0; i < maxNumberOfEnemies; ++i) {
		if (this->_enemies[i] == NULL) {
			int yCoord = std::rand() % 40;
			this->_enemies[i] = new Enemy(119, yCoord, 1);
			this->_map[yCoord][119] = 2;
			return;
		}
	}
}

void Battlefield::moveEnemies() {
	for (int i = 0; i < maxNumberOfEnemies; ++i) {
		if (this->_enemies[i] != NULL) {
			_map[this->_enemies[i]->getY()][this->_enemies[i]->getX()] = 0;
			this->_enemies[i]->setX(this->_enemies[i]->getX() - 1);
			_map[this->_enemies[i]->getY()][this->_enemies[i]->getX()] = 2;
		}
	}
}

void Battlefield::destroyEnemy() {
	for (int i = 0; i < maxNumberOfEnemies; ++i) {
		if (this->_enemies[i] != NULL && this->_enemies[i]->getX() == 1) {
			this->_map[this->_enemies[i]->getY()][this->_enemies[i]->getX()] = 0;
			delete this->_enemies[i];
			this->_enemies[i] = NULL;
		}
	}
}

void Battlefield::keyPressAction(Ship& player) {
	int key = getch();
	keypad(stdscr, TRUE);

	if (key == 32) {
		// player.shoot();
		std::cout << "huylan" << std::endl;
		return;
	}
	_map[player.getY()][player.getX()] = 0;
	if (key == KEY_UP) {
		player.moveUpwards();
	} else if (key == KEY_LEFT) {
		player.moveLeft();
	} else if (key == KEY_DOWN) {
		player.moveDownwards();
	} else if (key == KEY_RIGHT) {
		player.moveRight();
	}
	_map[player.getY()][player.getX()] = 1;
}

void Battlefield::colorInitialization() {
	start_color();
    init_pair(32, COLOR_WHITE, COLOR_BLACK);
    init_pair(33, 16, 16);
    init_pair(34, 241, 241);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
}

void Battlefield::topAndBottomBorders(int y, int x, int limit)
{
    attron(COLOR_PAIR(34));
    for (; x < limit; ++x) {
		mvprintw(y, x, "#");
    }
    attroff(COLOR_PAIR(34));
}

void Battlefield::leftAndRightBorders(int y, int x, int limit)
{
    attron(COLOR_PAIR(34));
    for (; y < limit; ++y) {
        mvprintw(y, x, "#");
    }
    attroff(COLOR_PAIR(34));
}

//operators

Battlefield& Battlefield::operator=(Battlefield const& rhs) {
	if (this != &rhs) {
		;
	}
	return *this;
}
