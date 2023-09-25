//Main program

#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

#include "Cell.h"
#include "TicTacToe.h"
#include "Player.h"
#include "RandomPlayer.h"
#include "HumanPlayer.h"
#include "MindfulPlayer.h"
#include "MonteCarloPlayer.h"
#include "MiniMaxPlayer.h"
#include "Game.h"

using namespace std;

int main() {
	srand(time(0));
	RandomPlayer* xplayer = new RandomPlayer('X');
//	MiniMaxPlayer* xplayer = new MiniMaxPlayer('X');
//	MonteCarloPlayer* oplayer = new MonteCarloPlayer('O');
	MindfulPlayer* oplayer = new MindfulPlayer('O');
//	RandomPlayer* oplayer = new RandomPlayer('O');

	Game game(xplayer, oplayer);

	game.play();

	return 0;
}
