#include "starmanMove.h"
#include "gameArena.h"
#include <iostream>

using namespace std;

/* Function Name: vicinitycheck
 *
 * Function Description:
 * This function checks if any of the game elements (Elon and the cars) are in the 3x3 vicinity of the player and displays them.
 *
 * Parameters:
 * The parameter "ge" is a pointer to the struct "gameElement".
 * The parameter "ga" is a pointer to the object of "gameArena".
 *
 * return value:
 * No return value.
 */


void starmanMove::vicinitycheck(gameElement* ge, gameArena* ga){
    int row = ge->user.row;
    int col = ge->user.column;
    vector <int>loc = {row-1,col-1,row-1,col,row-1,col+1,row,col-1,row,col+1,row+1,col-1,row+1,col,row+1,col+1};
    int row_pinto = ge->pinto.row;
    int col_pinto = ge->pinto.column;
    int row_yugo = ge->yugo.row;
    int col_yugo = ge->yugo.column;
    int row_roadster = ge->roadster.row;
    int col_roadster = ge->roadster.column;
    int row_musk = ge->musk.row;
    int col_musk = ge->musk.column;

    for(unsigned int i = 0; i < loc.size(); i = i+2){
        if(loc.at(i) == row_musk && loc.at(i+1) == col_musk){
            ga->setBoardElement(row_musk, col_musk, 'E');
        }
        if(loc.at(i) == row_pinto && loc.at(i+1) == col_pinto){
            ga->setBoardElement(row_pinto, col_pinto, 'P');
        }
        if(loc.at(i) == row_roadster && loc.at(i+1) == col_roadster){
            ga->setBoardElement(row_roadster, col_roadster, 'R');
        }
        if(loc.at(i) == row_yugo && loc.at(i+1) == col_yugo){
            ga->setBoardElement(row_yugo, col_yugo, 'Y');
        }
    }
}

/* Function Name: userMove
 *
 * Function Description:
 * This function helps move the Player with /'w'/'a'/'s'/'d'/ keys entered by the player.
 *
 * Parameters:
 * The parameter "ge" is a pointer to the struct "gameElement".
 * The parameter "ga" is a pointer to the object of "gameArena".
 *
 * return value:
 * No return value.
 */


void starmanMove::userMove(gameElement* ge, gameArena* ga){

    char cIn=' ';

    while(true){
        cout << endl<<"WHAT'S YOUR NEXT MOVE?\n";
        cin >> cIn;
        cIn = toupper(cIn);
        if (!(cIn == 'A' || cIn == 'S' || cIn == 'D' || cIn == 'W' || cIn == 'Q'))
            cout << endl <<"ENTER A VALID MOVE OUT OF [A | S | D | W | Q - twice to quit the game]\n TRY AGAIN" << endl;
        else
            break;
    }

    quitGame(cIn);
    int row = ge->user.row;
    int col = ge->user.column;

    while(true){
        if (borderCheck(row, col, cIn)){
            if((row + col)%2==0)
                ga->setBoardElement(row, col, char(219));
            else
                ga->setBoardElement(row, col, char(255));

            if (cIn == 'a' || cIn == 'A'){
                ge->user.column-=1;
                col = ge->user.column;
                ga->setBoardElement(row, col, 'U');
            }
            else if (cIn == 'd' || cIn == 'D'){
                ge->user.column+=1;
                col = ge->user.column;
                ga->setBoardElement(row, col, 'U');
            }
            else if (cIn == 'w' || cIn == 'W'){
                ge->user.row-=1;
                row = ge->user.row;
                ga->setBoardElement(row, col, 'U');
            }
            else if (cIn == 's' || cIn == 'S'){
                ge->user.row+=1;
                row = ge->user.row;
                ga->setBoardElement(row, col, 'U');
            }
        }
        break;
    }
}

/* Function Name: borderCheck
 *
 * Function Description:
 * This function helps make sure that a player does not go out of the board while its position is on the extremes.
 *
 * Parameters:
 * The "row" parameter has the row-number (ordinate) of a particular position of the user on the board.
 * The "col" parameter has the column-number (co-ordinate) of a particular position of the user on the board.
 * The "c" parameter is the character  /'w'/'a'/'s'/'d'/ which is to be entered by the player.
 *
 * return value:
 * The function returns false if the player tries to go off the board and returns true otherwise.
 */


bool starmanMove::borderCheck(int row, int col, char c){
    if (row == 0 && (c == 'w' || c == 'W')){
            cout <<endl <<"Y O U   H I T   A   W A L L!!!\n T R Y   A   D I F F E R E N T   M O V E" <<endl;
            return false;
    }
    if (row == 14 && (c == 's' || c == 'S')){
        cout <<endl <<"Y O U   H I T   A   W A L L!!!\n T R Y   A   D I F F E R E N T   M O V E" <<endl;
        return false;
}
    if (col == 0 && (c == 'a' || c == 'A')){
        cout <<endl <<"Y O U   H I T   A   W A L L!!!\n T R Y   A   D I F F E R E N T   M O V E" <<endl;
        return false;
}
    if (col == 14 && (c == 'd' || c == 'D')){
        cout <<endl <<"Y O U   H I T   A   W A L L!!!\n T R Y   A   D I F F E R E N T   M O V E" <<endl;
        return false;
}
    return true;
}

/* Function Name: yugoDetect
 *
 * Function Description:
 * This function checks if the player enters the Yugo car.
 *
 * Parameters:
 * The "ge" parameter is a pointer to the struct of "gameElements".
 *
 * return value:
 * This functions returns true if the player enters the Yugo car and returns false otherwise.
 */


bool starmanMove::yugoDetect(gameElement* ge){
        if (ge->user.row == ge->yugo.row && ge->user.column == ge->yugo.column){
            cout << endl<<"YOU GOT INTO THE WRONG CAR!!!!" << endl;
            cout<<"THIS IS YUGO!!!!"<<endl;
            cout<<"YOU GOT CAUGHT!!!"<<endl;
            ge->yugo.encounters++;
            return true;
        }
    return false;
}

/* Function Name: pintoDetect
 *
 * Function Description:
 * This function checks if the player enters the Pinto car.
 *
 * Parameters:
 * The "ge" parameter is a pointer to the struct of "gameElements".
 *
 * return value:
 * This functions returns true if the player enters the Pinto car and returns false otherwise.
 */

bool starmanMove::pintoDetect(gameElement* ge){
    if (ge->user.row == ge->pinto.row && ge->user.column == ge->pinto.column){
        cout << endl<<"YOU GOT INTO THE WRONG CAR!!!!" << endl;
        cout<<"THIS IS PINTO!!!!"<<endl;
        cout<<"YOU GOT CAUGHT!!!"<<endl;
        ge->pinto.encounters++;
        return true;
    }
    return false;
}

/* Function Name: roadsterDetect
 *
 * Function Description:
 * This function checks if the player enters the Roadster car.
 *
 * Parameters:
 * The "ge" parameter is a pointer to the struct of "gameElements".
 *
 * return value:
 * This functions returns true if the player enters the Roadster car and returns false otherwise.
 */

bool starmanMove::roadsterDetect(gameElement* ge1){
    if (ge1->user.row == ge1->roadster.row && ge1->user.column == ge1->roadster.column){
        ge1->roadster.encounters++;
        cout << endl <<"Y O U  S A V E D  T H E  R O A D S T E R !!!!!!!\n Y O U  H A V E  W O N  T H E  G A M E!!!!\n" << endl;
        return true;
    }
    return false;
}

/* Function Name: quitGame
 *
 * Function Description:
 * This function works when the user wants to quit the game.
 *
 * Parameters:
 * The "c" parameter is the character entered by the player.
 *
 * return value:
 * No return value
 */

void starmanMove::quitGame(char c){
    if (c == 'Q' || c == 'q'){
        cout << endl << "ARE YOU SURE YOU WANT TO QUIT? [Y - YES | ANY OTHER KEY - NO]\n";
        char cIn = ' ';
        cin >> cIn;
        if (cIn == 'Y' || cIn == 'y'){
            cout << endl << "Y O U   Q U I T\n G A M E   O V E R\n";
            exit(0);
        }
        else
            return;
    }
}


