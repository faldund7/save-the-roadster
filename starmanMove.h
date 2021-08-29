#ifndef STARMANMOVE_H
#define STARMANMOVE_H
#include "gameArena.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class starmanMove{

    private:

    public:
        void userMove(gameElement*, gameArena*);
        bool yugoDetect(gameElement*);
        bool pintoDetect(gameElement*);
        bool roadsterDetect(gameElement*);
        void vicinitycheck(gameElement*, gameArena*);
        bool borderCheck(int, int, char);
        void quitGame(char);
};

#endif // STARMANMOVE_H
