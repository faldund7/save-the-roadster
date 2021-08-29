#ifndef MUSKMOVE_H
#define MUSKMOVE_H

#include "gameArena.h"
#include "starmanMove.h"
#include "initiateGame.h"
#include "clues.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class muskMove{

    private:

    public:
    void elonMove(gameElement*, gameArena*);
    bool mineDetect(gameElement* );
    bool muskDetect(gameArena*, gameElement*);
    bool muskBorderCheck(int, int, int);

};





#endif // MUSKMOVE_H
