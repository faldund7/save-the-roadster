#ifndef CLUES_H
#define CLUES_H

#include "gameArena.h"
#include "starmanMove.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class clues{
    private:

    public:
        double calcDistance(gameArena*);
        void proximity(gameArena*, gameElement*);
        void messageDisplay1();
        void messageDisplay2();
        void elonAwake(gameArena*, gameElement*);
        void mineReactivation(gameArena*, gameElement*);
        void gameStatistics(gameElement*);
};


#endif // CLUES_H
