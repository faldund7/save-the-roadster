#include <iostream>
#include "clues.h"
#include "gameArena.h"
#include "initiateGame.h"
#include "starmanMove.h"
#include "muskMove.h"

using namespace std;

/* Function Name: elonMove
 *
 * Function Description:
 * This function helps to move Elon Musk. Elon Musk only moves after the detonation of a mine.
 *
 * Parameters:
 * The parameter "ge" is a pointer to the struct "gameElement".
 * The parameter "ga" is a pointer to the object of "gameArena".
 *
 * return value:
 * No return value.
 */

void muskMove::elonMove(gameElement *ge, gameArena *ga){
    srand(time(0));
    int randPos = (rand()%4 + 1);

    int row = ge->musk.row;
    int col = ge->musk.column;
    if((row + col)%2==0)
        ga->setBoardElement(row, col, char(219));
    else
        ga->setBoardElement(row, col, char(255));

    while(true){
        if(muskBorderCheck(row, col, randPos)){
            if (randPos==1){
                ge->musk.column-=1;
                col = ge->musk.column;
            }
            else if (randPos==2){
                ge->musk.column+=1;
                col = ge->musk.column;
            }
            else if (randPos==3){
                ge->musk.row+=1;
                row = ge->musk.row;
            }
            else if (randPos==4){
                ge->musk.row-=1;
                row = ge->musk.row;
            }
            break;
        }
    }
}

/* Function Name: muskBorderCheck
 *
 * Function Description:
 * This function helps make sure that Elon Musk does not go off the board displayed to the user.
 *
 * Parameters:
 * The "row" parameter has the row-number (ordinate) of Elon Musk's position on the board.
 * The "col" parameter has the column-number (co-ordinate) of Elon Musk's position on the board.
 * The "i" parameter is a random number generated which is assigned to /'left'/'right'/'up'/'down'/ to move Elon Musk.
 *
 * return value:
 * The function returns true if Musk is on the board and returns false if Musk tries to move off the board.
 */

bool muskMove::muskBorderCheck(int row, int col, int i){
    if (col == 0 && i == 1){
            return false;
    }
    if (col == 14 && i == 2){
        return false;
        }
    if (row == 0 && i == 3){
        return false;
        }
    if (row == 14 && i == 4){
        return false;
        }
    return true;
}

/* Function Name: mineDetect
 *
 * Function Description:
 * This function detects if the user stepped on a mine and then wakes Elon Musk.
 *
 * Parameters:
 * The "ge" parameter is a pointer which points to the struct of "gameElements".
 *
 * return value:
 * This functions returns true if a mine is detected and returns false otherwise.
 */


bool muskMove::mineDetect(gameElement* ge){
    for(int i = 0; i <= 49; i++)
        if (ge->user.row == ge->mines[i].row && ge->user.column == ge->mines[i].column){
            cout<<endl<<"KAAAAAABBBOOOOOOOOMMMMMMM !!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            cout<<"YOU STEPPED ON A MINE"<<endl;
            cout<<"ELON MUSK IS NOW AWAKE !!!!"<<endl;
            cout<<"HE MIGHT CATCH YOU ANYTIME SO BE CAREFUL !!!"<<endl;
            return true;
            }
    return false;
}

/* Function Name: muskDetect
 *
 * Function Description:
 * This function checks if Elon Musk caught the player and gives the player only one more chance to escape.
 *
 * Parameters:
 * The parameter "ge" is a pointer to the struct "gameElement".
 * The parameter "ga" is a pointer to the object of "gameArena".
 *
 * return value:
 * This function returns true if the player is caught by Musk and return false otherwise.
 */


bool muskMove::muskDetect(gameArena* ga, gameElement* ge){
    if (ge->user.row == ge->musk.row && ge->user.column == ge->musk.column){
        ge->musk.encounters++;

        if (ge->musk.encounters > 1){
            cout << endl <<"Y O U   W E R E   C A U G H T    F O R   T H E   S E C O N D   T I M E!!!\n Y O U   H A V E   L O S T.\n G A M E   O V E R"<<endl;
            ge->musk.encounters--;
            return true;
        }
        else {
            cout <<endl <<"M U S K   C A U G H T   Y O U" << endl;
            cout <<  "YOU WILL GET ONE MORE CHANCE TO SAVE THE ROADSTER" << endl;
            int row = ge->user.row;
            int col = ge->user.column;

            if((row + col)%2==0)
                ga->setBoardElement(row, col, char(219));
            else
                ga->setBoardElement(row, col, char(255));

            ge->user.row = (rand()%14) + 1;
            ge->user.column = (rand()%14) + 1;
            ga->setBoardElement(ge->user.row, ge->user.column,'U');
        }
    }
    return false;
}

