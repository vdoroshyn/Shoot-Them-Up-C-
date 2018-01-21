#include "Battlefield.hpp"

Battlefield::Battlefield() {
	nullEnemiesArray();
	nullBulletsArray();
	this->_ammo = maxNumberOfBullets;
	this->_score = 0;
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
	for (int i = 0; i < maxNumberOfEnemies; ++i) {
		if (this->_enemies[i] != NULL) {
			delete this->_enemies[i];
		}
	}

	for (int i = 0; i < maxNumberOfBullets; ++i) {
		if (this->_bullets[i] != NULL) {
			delete this->_bullets[i];
		}
	}

	endwin();
	system("clear");
	std::cout << "Game Over! Points scored: " << this->_score << ". Better luck next time!" << std::endl;
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
	this->topAndBottomBorders(0, 0, 122);
	this->topAndBottomBorders(42, 0, 123);
	this->leftAndRightBorders(0, 0, 42);
	this->leftAndRightBorders(0, 122, 42);
	
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
	mvprintw(yMap + 3, 0, "Score: %d", this->_score);
	mvprintw(yMap + 3, xMap - 4, "Ammo: %d", this->_ammo);
	refresh();
}


void Battlefield::nullEnemiesArray() {
	for (int i = 0; i < maxNumberOfEnemies; ++i) {
		this->_enemies[i] = NULL;
	}
}

void Battlefield::playerInitalPosition(Ship& player) {
	this->_map[player.getY()][player.getX()] = 1;
}

void Battlefield::generateEnemy() {
	int random = std::rand() % 10;

	for (int i = 0; i < maxNumberOfEnemies; ++i) {
		if (this->_enemies[i] == NULL && random == 1) {
			int yCoord = std::rand() % 40;

			this->_enemies[i] = new Enemy(119, yCoord, 1);
			this->_map[yCoord][119] = 2;
			return;
		}
	}
}

void Battlefield::moveEnemies(Ship& player) {
	for (int i = 0; i < maxNumberOfEnemies; ++i) {
		if (this->_enemies[i] != NULL) {
			int enemyX = this->_enemies[i]->getX();
			int enemyY = this->_enemies[i]->getY();

			if (enemyX >= 2 && this->_map[enemyY][enemyX - 1] == 3) {

				for (int j = 0; j < maxNumberOfBullets; ++j) {
					if (_bullets[j] != NULL) {
						int bulletX = this->_bullets[j]->getX();
						int bulletY = this->_bullets[j]->getY();

						if (bulletY == enemyY && bulletX == enemyX - 1) {
							this->_map[bulletY][bulletX] = 0;
							delete this->_bullets[j];
							this->_bullets[j] = NULL;
							this->_score += 1;
							this->_ammo += 1;
							break;
						}
					}
				}
				this->_map[enemyY][enemyX] = 0;
				delete this->_enemies[i];
				this->_enemies[i] = NULL;
			} else if (enemyX >= 2 && this->_map[enemyY][enemyX - 1] == 1) {
				player.setHP(0);
				return;
			} else if (enemyX >= 3 && this->_map[enemyY][enemyX - 2] == 1) {
				player.setHP(0);
				return;
			} else {
				this->_map[this->_enemies[i]->getY()][this->_enemies[i]->getX()] = 0;
				this->_enemies[i]->setX(this->_enemies[i]->getX() - 1);
				this->_map[this->_enemies[i]->getY()][this->_enemies[i]->getX()] = 2;
			}
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

void Battlefield::nullBulletsArray() {
	for (int i = 0; i < maxNumberOfBullets; ++i) {
		this->_bullets[i] = NULL;
	}
}

void Battlefield::generateBullet(Ship& player) {
	for (int i = 0; i < maxNumberOfBullets; ++i) {
		if (this->_bullets[i] == NULL) {
			int x = player.getX();
			int y = player.getY();

			this->_bullets[i] = new Bullet(x + 1, y, 1);
			this->_map[y][x + 1] = 3;
			this->_ammo -= 1;
			return;
		}
	}
}

void Battlefield::moveBullets() {
	for (int i = 0; i < maxNumberOfBullets; ++i) {
		if (this->_bullets[i] != NULL) {
			int bulletX = this->_bullets[i]->getX();
 			int bulletY = this->_bullets[i]->getY();

			if (bulletX <= 119 && this->_map[bulletY][bulletX + 1] == 2) {

				for (int j = 0; j < maxNumberOfEnemies; ++j) {
					if (_enemies[j] != NULL) {
						int enemyX = this->_enemies[j]->getX();
						int enemyY = this->_enemies[j]->getY();

						if (enemyY == bulletY && enemyX == bulletX + 1) {
							this->_map[enemyY][enemyX] = 0;
							delete this->_enemies[j];
							this->_enemies[j] = NULL;
							this->_score += 1;
							break;
						}
					}
				}

				this->_map[bulletY][bulletX] = 0;
				delete this->_bullets[i];
				this->_bullets[i] = NULL;
				this->_ammo += 1;
			} else {
				this->_map[bulletY][bulletX] = 0;
				this->_bullets[i]->setX(bulletX + 1);
				this->_map[bulletY][bulletX + 1] = 3;
			}
		}
	}
}

void Battlefield::destroyBullet() {
	for (int i = 0; i < maxNumberOfBullets; ++i) {
		if (this->_bullets[i] != NULL && this->_bullets[i]->getX() == 119) {
			this->_map[this->_bullets[i]->getY()][this->_bullets[i]->getX()] = 0;
			delete this->_bullets[i];
			this->_bullets[i] = NULL;
			this->_ammo += 1;
		}
	}
}

void Battlefield::keyPressAction(Ship& player) {
	int key = getch();
	keypad(stdscr, TRUE);

	if (key == 32) {
		this->generateBullet(player);
		return;
	}
	this->_map[player.getY()][player.getX()] = 0;
	if (key == KEY_UP) {
		player.moveUpwards();
	} else if (key == KEY_LEFT) {
		player.moveLeft();
	} else if (key == KEY_DOWN) {
		player.moveDownwards();
	} else if (key == KEY_RIGHT) {
		player.moveRight();
	}
	this->_map[player.getY()][player.getX()] = 1;
}

void Battlefield::removeDelay() {
	nodelay(stdscr, TRUE);
	double pause = (1.0 / 20.0);
	usleep(pause * 1000000.0);
}

void Battlefield::colorInitialization() {
	start_color();
    init_pair(32, COLOR_WHITE, COLOR_BLACK);
    init_pair(33, 16, 16);
    init_pair(34, 241, 241);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
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
		for (int i = 0; i < maxNumberOfEnemies; ++i) {
			this->_enemies[i] = rhs._enemies[i];
		}

		for (int i = 0; i < maxNumberOfBullets; ++i) {
			this->_bullets[i] = rhs._bullets[i];
		}

		for (int i = 0; i < yMap; ++i) {
			for (int j = 0; j < xMap; ++j) {
				this->_map[i][j] = rhs._map[i][j];
			}
		}
		this->_score = rhs._score;
		this->_ammo = rhs._ammo;
	}
	return *this;
}
