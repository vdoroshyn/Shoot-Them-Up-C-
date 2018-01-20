#ifndef BATTLEFIELD_HPP
#define BATTLEFIELD_HPP 

#include <ncurses.h>
#include "Ship.hpp"
#include "Enemy.hpp"
#include <unistd.h>

int const yMap = 40;
int const xMap = 120;
int const maxNumberOfEnemies = 3;

class Battlefield {
    public:
        Battlefield();
        ~Battlefield();
        Battlefield(Battlefield const& cpy);

        void initializeMap();
        void mapToScreen();
        void nullEnemiesArray();
        void generateEnemy();
        void moveEnemies();
        void destroyEnemy();
        void keyPressAction(Ship& player);
        void colorInitialization();
        void topAndBottomBorders(int y, int x, int limit);
        void leftAndRightBorders(int y, int x, int limit);

        int _map[yMap][xMap];
        Enemy* _enemies[3];

        Battlefield& operator=(Battlefield const& rhs);
    protected:
    private:
};



#endif
