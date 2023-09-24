//Main program

#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#include "Cell.h"
#include "TicTacToe.h"
#include "MiniMaxPlayer.h"
#include "HumanPlayer.h"
#include "Game.h"

using namespace std;

int main() {
	srand(time(0));

	Game game;

	game.play();

	return 0;
}
