#include <iostream>
#include <ctime>

using namespace std;

#include "TicTacToe.h"

int main()
{
	srand(time(0));
     TicTacToe board;
     board.play();

     return 0;
}


