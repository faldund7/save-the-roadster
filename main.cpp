/*
 * Project Title:
 * - The Tesla Game
 * Description:
 * This program allows you to play a very interactive game called "Tesla" where-in the player has to save Elon Musk's
 * prized "Roadster" before it is blasted into the Space.
 *
 * Developers:
 * - Dhruv Raj Bangad - bangaddj@mail.uc.edu
 * - Nishil Faldu - faldund@mail.uc.edu
 *
 * Help Received:
 * - TA Name one:
 * - Instructor:
 * - Student X: Pranav Mahajan
 *
 * Special Instructions:
 * - How to compile
 * - How to run it
 *
 * Developer comments:
 * We really appreciate the hard work we put into this project and we are truly proud of our creation. We have worked
 * on this project for a week putting a minimum of 5 hours daily. We used Microsoft Teams to share our screens where one
 * used to code and the other used to actively involve in reviewing each line and logic of the code.
 *
 * Developer 1 - Dhruv Raj Bangad:
 * We both both worked on the code on simultaneous days. While one of us was typing the code, the other was
 * giving new ideas and checking the code at every moment. So similar to my partner my role was to code,
 * give new ideas and check for any errors.
 * Apart from this, I got to learn a lot about my coding skills. I realized that knowing a language and using it are
 * two different things. Each is a challenge of its own. This project gave me the opportunity to learn the art of using C++
 * to a much greater extent than before. I learnt a lot about application development and file management.
 * I am very grateful of the instuctors and professors to provide us both with this opportunity.
 *
 * Developer 2 - Nishil Faldu:
 * We succesfully executed the pair programming approach to creating this project.
 * We swapped roles every day. On one day, my partner was actively involved in programming task.
 * While I was focusing more on the overall direction, reviewing each of line of code as it is typed in.
 * While reviewing, I came up with ideas for improvements and likely future problems to address.
 * I learned some significances of the pair programming such as a team or a pair can solve a problem faster.
 * I learned significantly more through this projects and learned a few things that I did not think could be possible.
 * One of such things is struct within a struct. We used a struct to store the elements of the game and to each of the
 * elements we assigned the datatype of another struct that stored the co-ordinates of those elements.
 * I now feel confident with Object Oriented Programming approach.
 * I thoroughly enjoyed working with my partner which has essentially ingrained in me the importance of teamwork. I have
 * no doubts on how to use a pointer now because in this project we used a pointer for everything. I acknowledge
 * and appreciate the fact that my partner is a better programmer than me and I have learned a lot from him during
 * the tenure of this project. I have also realized that I can be good at debugging codes and could dive deeper
 * into debugging.
 */


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

using namespace std;



int main()
{
    gameArena g2;
    gameArena* g2P = &g2;
    initiateGame ig;
    ig.initiate(g2P, g2.getGE());

    return 0;
}
