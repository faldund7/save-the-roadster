#ifndef GAMEARENA_H
#define GAMEARENA_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
struct loc{
    int row;
    int column;
    int encounters;
};
struct gameElement{
    loc mines[50] ;
    loc musk;
    loc user;
    loc yugo;
    loc pinto;
    loc roadster;
};

class gameArena{
  private:
      gameElement ge;
      gameElement* gePointer;
      const unsigned int BLACK = 255;
      const unsigned int WHITE = 219;
      const unsigned int ROWS = 15;
      const unsigned int COLUMNS = 15;
      const unsigned int BLOCK_WIDTH = 2;
      const unsigned int BLOCK_LENGTH = 1;
      char board[15][15];
      char (*boardP)[15][15];

  public:
      gameArena();
      bool boardGenerate();
      bool posAlloc();
      bool boardDisplay();
      gameElement* getGE();
      void setBoardElement(int row, int col, char c);
      void rulesDisplay();
};


#endif // GAMEARENA_H
