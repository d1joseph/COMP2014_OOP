/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.

Author: Dhivyan Joseph
StudentId: 18225899
**************************/
#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

#include "OneDArray.h"
#include "TicTacToe.h"
#include "RandomPlayer.h"
#include "HumanPlayer.h"
#include "NBTicTacToe.h"

using namespace std;

int main() {
    srand(time(0));

    HumanPlayer o;
    RandomPlayer x;

    NBTicTacToe game(o,x);
    game.play(o,x);

    return 0;
}