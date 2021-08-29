#include "gameArena.h"
#include "starmanMove.h"
#include <iostream>
#include <vector>

using namespace std;

/* Function Name: gameArena (Constructor)
 *
 * Function Description:
 * Declares all the variables and intitializes all of them.
 *
 * Parameters:
 * No parameters needed.
 *
 * return value:
 * A constructor does not require a return statement.
 */

gameArena::gameArena(){
    gePointer = &ge;
    boardP = &board;
    ge.musk.encounters = 0;
    ge.yugo.encounters = 0;
    ge.pinto.encounters = 0;
    ge.roadster.encounters = 0;
}

/* Function Name: rulesDisplay
 *
 * Function Description:
 * Displays the story and rules of the Game at the start.
 *
 * Parameters:
 * No parameters needed
 *
 * return value:
 * There is no return statement.
 */

void gameArena::rulesDisplay(){
    cout << "We have created a simple version of a classic game TESLA in C++." << endl;
    cout << endl;
    cout << "The player starts in a random position on a checkered floor of a room in SpaceX." << endl;
    cout << endl;
    cout << "Goal: In this game, you will have to save Elon Musk\'s prized Tesla Roadster from being sent" << endl;
    cout << "into space before becoming the STARMAN." << endl;
    cout << endl;
    cout << "Story: You find your way to SpaceX the night before the Roadster is mounted atop the rocket" << endl;
    cout << "which is to send it into space. The building is dark and the Roadster is hidden somewhere in" << endl;
    cout << "a large open dark room. In addition to the Roadster, two other cars (a Yugo and a Pinto) are" << endl;
    cout << "being stored in the same facility as well. ELON MUSK is sleeping somewhere in the same room" << endl;
    cout << "and you have to avoid waking him to find your way to the Roadster. Once awoken he will randomnly" << endl;
    cout << "move through the building looking for you. If he lands next to you, you can get away from him only" << endl;
    cout << "once. The second time you will be the STARMAN and blasted into the space with his Roadster. Once" << endl;
    cout << "he is awake your only chance to avoid being STARMAN is to make your escape in his roadster. If you" << endl;
    cout << "get into either of the two cars you will be caught and become the STARMAN." << endl;
    cout << endl;
    cout << "This article states the rules of the TESLA game:" << endl;
    cout << "1) The player will be starting in a random unoccupied location in SpaceX." << endl;
    cout << "2) The player will be indicated as \"UU\"." << endl;
    cout << "3) The player will have to enter w (forward/north), a (left/west), s (backward/south), d(right/east)" << endl;
    cout << "for movement directions." << endl;
    cout << "4) The player will be guided to the proper location of the Roadster by issuing a hint which will" << endl;
    cout << "state if the user is GETTING FAR or GETTING CLOSER to the Roadster. You will not be told to go in" << endl;
    cout << "a specific direction." << endl;
    cout << "5) Intitially, Elon Musk is sleeping in the same room of SpaceX. You will know the postion of ELON MUSK while he is sleeping" << endl;
    cout << "It will be indicated on the screen as \"EE\". There are 50 MINES that will be detonated when the player steps on them." << endl;
    cout << "No sooner the first MINE is triggered, ELON MUSK WAKES UP and he will start chasing you. BEWARE: ELON MUSK MOVES FASTER THAN YOU." << endl;
    cout << "6) Once the game is over you will be asked to play again and if chose to do so, you will be placed in the room again at a different location." << endl;
    cout << "7) The player will be able to quit the game anytime. The player must hit Q to quit the game. Once you choose to quit the game," << endl;
    cout << "your statistics will be displayed about the number of turns it took the player to" << endl;
    cout << "find the roadster, the number of times the roadster was found, and the number of times the player became STARMAN." << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

/* Function Name: boardDisplay
 *
 * Function Description:
 * This function displays the board (SpaceX Room).
 *
 * Parameters:
 * No parameters needed
 *
 * return value:
 * True is returned as it is a "bool" function.
 */

bool gameArena::boardDisplay(){
    for(unsigned int i = 0; i < ROWS; i++){
       for(unsigned int l = 0; l < BLOCK_LENGTH; l++){
          for(unsigned int j = 0; j < COLUMNS; j++){
              for(unsigned int k = 0; k < BLOCK_WIDTH; k++){
                cout << board[i][j];
                    }
                }
                cout << endl;
             }
          }
     return true;
}

/* Function Name: boardGenerate
 *
 * Function Description:
 * This function generates a board (SpaceX Room) for the game.
 *
 * Parameters:
 * No parameteres needed.
 *
 * return value:
 * True is returned as it is a "bool" function.
 */

bool gameArena::boardGenerate(){
    for(unsigned int i = 0; i < ROWS; i++){
        for(unsigned int j = 0; j < COLUMNS; j++){
            if((i + j) % 2 == 0){
                board[i][j] = static_cast<char>(WHITE);
            }
            else{
                board[i][j] = static_cast<char>(BLACK);
            }
        }
    }
    return true;
}

/* Function Name: posAlloc
 *
 * Function Description:
 * This function generates random numbers (which will be used as coordinates) for allocating positions to the elements of the game on the board.
 *
 * Parameters:
 * No parameters needed.
 *
 * return value:
 * True is returned as it is a "bool" function.
 */

bool gameArena::posAlloc(){
    srand(time(0));
    for (int i = 0; i<50; i++){
    ge.mines[i].row = (rand()%14) + 1;
    ge.mines[i].column = (rand()%14) + 1;
    }

    ge.musk.row = (rand()%14) + 1;
    ge.musk.column = (rand()%14) + 1;

    ge.roadster.row = (rand()%14) + 1;
    ge.roadster.column = (rand()%14) + 1;

    ge.yugo.row = (rand()%14) + 1;
    ge.yugo.column = (rand()%14) + 1;

    ge.pinto.row = (rand()%14) + 1;
    ge.pinto.column = (rand()%14) + 1;

    ge.user.row = (rand()%14) + 1;
    ge.user.column = (rand()%14) + 1;
    board[ge.user.row][ge.user.column] = 'U';

    return true;
}

/* Function Name: setBoardElement
 *
 * Function Description:
 * This function is a "set" function and it actually prints the game elements on the Board.
 *
 * Parameters:
 * The "row" parameter has the row-number (ordinate) of a particular position on the board.
 * The "col" parameter has the column-number (co-ordinate) of a particular position on the board.
 * The "c" parameter is the character which is to be printed on the board to represent a game element.
 *
 * return value:
 * There is no return statement.
 */

void gameArena::setBoardElement(int row, int col, char c){
    board[row][col] = c;
}

/* Function Name: getGE
 *
 * Function Description:
 * This function is a "get" function that gets the pointer to the structure of "gameElements".
 *
 * Parameters:
 * No parameters needed.
 *
 * return value:
 * A pointer to the struct of gameElemts is returned.
 */

gameElement* gameArena::getGE(){
   return gePointer;
}

