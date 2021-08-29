#include "gameArena.h"
#include "starmanMove.h"
#include "clues.h"
#include "initiateGame.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/* Function Name: initiate
 *
 * Function Description:
 * This function initiates the Tesla Game.
 *
 * Parameters:
 * The "ga" parameter is a pointer to the object of "gameArena".
 * The "ge" parameter is a pointer to the struct of "gameElement".
 *
 * return value:
 * No return value.
 */

void initiateGame::initiate(gameArena *ga, gameElement *ge){
    clues c;
    char ch = ' ';
    int turns = 0;
    //ga->rulesDisplay();
    while (true){
        ga->boardGenerate();
        ga->posAlloc();
        ga->boardDisplay();
        c.proximity(ga, ge);
        c.gameStatistics(ge);

        cout << endl<<"DO YOU WANT TO PLAY AGAIN? [Y - YES | N - NO ]"<<endl;
        cin >> ch;
        if ((ch == 'Y' || ch == 'y')){
            turns++;
            continue;
        }
        else if ((ch == 'N' || ch == 'n')){
            c.gameStatistics(ge);
            cout <<"YOU TOOK "<<turns<<" TO FIND THE ROADSTER" << endl;
            exit(0);
        }
    }
}
