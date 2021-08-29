#include "gameArena.h"
#include "starmanMove.h"
#include "clues.h"
#include "muskMove.h"
#include <iostream>
#include <vector>

using namespace std;

/* Function Name: calcDistance
 *
 * Function Description:
 * This function calculates the distance between the Roadster and the Player after every move that Player makes.
 *
 * Parameters:
 * The "ga" parameter is the pointer to the object of class "gameArena".
 *
 * return value:
 * Distance between the Roadster and the Player (keeps varying).
 */

double clues::calcDistance(gameArena* ga){
    int rowU, colU, rowR, colR;
    double dist=0.0;
    rowU = ga->getGE()->user.row;
    colU = ga->getGE()->user.column;
    rowR = ga->getGE()->roadster.row;
    colR = ga->getGE()->roadster.column;
    dist = sqrt(pow((rowR - rowU), 2) + pow((colR - colU), 2));
    return dist;
}

/* Function Name: proximity
 *
 * Function Description:
 * This function decides whether the Player is getting far or closer to the Roadster and displays a hint accordingly.
 *
 * Parameters:
 * The "ga" parameter is the pointer to the object of class "gameArena".
 * The "ge" parameter is the pointer to the structure of "gameElement" in "gameArena.
 *
 * return value:
 * As it is a void function it has no return value.
 */

void clues::proximity(gameArena* ga, gameElement* ge){
    starmanMove sm;
    muskMove mm;
    double initialD = 0.0, finalD = 0.0;
    initialD = calcDistance(ga);

    while(!(mm.muskDetect(ga, ge) || sm.roadsterDetect(ge) || sm.yugoDetect(ge) || sm.pintoDetect(ge))){
        sm.userMove(ge, ga);
        sm.vicinitycheck(ge, ga);
        finalD = calcDistance(ga);

        if(mm.mineDetect(ge)){
            ga->boardDisplay();
            if ((finalD-initialD) > 0)
                messageDisplay1();
            else
                messageDisplay2();
            initialD = finalD;
            break;
        }

        ga->boardDisplay();

        if ((finalD-initialD) > 0)
            messageDisplay1();
        else
            messageDisplay2();
        initialD = finalD;
    }
        elonAwake(ga, ge);
}

/* Function Name: elonAwake
 *
 * Function Description:
 * No sooner the mine is detonated by the player, this function wakes Elon Musk and continues the game.
 *
 * Parameters:
 * The "ga" parameter is the pointer to the object of class "gameArena".
 * The "ge" parameter is the pointer to the structure of "gameElement" in "gameArena.
 *
 * return value:
 * As it is a void function it has no return value.
 */

void clues::elonAwake(gameArena* ga, gameElement* ge){
    starmanMove sm;
    muskMove mm;
    double initialD, finalD = 0.0;
    initialD = calcDistance(ga);

    while(!(mm.muskDetect(ga, ge) || sm.roadsterDetect(ge) || sm.yugoDetect(ge)|| sm.pintoDetect(ge))){
        sm.userMove(ge, ga);
        mm.elonMove(ge, ga);
        mm.elonMove(ge, ga);
        sm.vicinitycheck(ge, ga);
        finalD = calcDistance(ga);

        if ((finalD-initialD) > 0)
            messageDisplay1();
        else
            messageDisplay2();

        ga->boardDisplay();
    }
    initialD = finalD;
}

/* Function Name: gameStatistics
 *
 * Function Description:
 * This function displays statistics of the game once it ends: Number of times you found the Roadster and the Number of times you became STARMAN.
 *
 * Parameters:
 * The "ge" parameter is the pointer to the structure of "gameElement" in "gameArena".
 *
 * return value:
 * As it is a void function it has no return value.
 */

void clues::gameStatistics(gameElement *ge){
    cout <<endl <<"YOU CAME ACROSS ROADSTER "<<ge->roadster.encounters<<" TIMES"<<endl;
    cout << endl << "YOU BECAME STARMAN " << ge->musk.encounters + ge->yugo.encounters + ge->pinto.encounters<< " TIMES"<<endl;

}

/* Function Name: messageDisplay1
 *
 * Function Description:
 * Displays a message if you the Player is going farther from the Roadster.
 *
 * Parameters:
 * No parameters needed
 *
 * return value:
 * As it only prints a message, there is no return statement.
 */

void clues::messageDisplay1(){
        cout << endl <<"Y O U   A R E   G E T T I N G   F A R T H E R  F R O M   T H E   R O A D S T E R !!!!\n";
}

/* Function Name: messageDisplay2
 *
 * Function Description:
 * Displays a message if you the Player is getting closer to the Roadster.
 *
 * Parameters:
 * No parameters needed
 *
 * return value:
 * As it only prints a message, there is no return statement.
 */

void clues::messageDisplay2(){
        cout << endl <<"Y O U   A R E   G E T T I N G   C L O S E R !!!!\nY O U   C A N   S A V E   T H E   R O A D S T E R !!!!\n";
}
