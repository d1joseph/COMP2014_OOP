#include "..\Task4_3\TicTacToe.h"

#include <iostream>

using namespace std;

class Game {
public:
	Game();
    void play();
    void getXMove(char player, int&, int&);
    void getOMove(char player, int&, int&);
private:
    TicTacToe board;
	int noOfMoves;
};

Game::Game() {
	noOfMoves = 0;
}

void Game::getXMove(char player, int &x, int &y) {
    if (noOfMoves >= 9) {
		return false;
	}

	// rng seed
	srand(time(0));

	int row, col;
	do {
		row = rand() % BOARDSIZE + 1;
		col = rand() % BOARDSIZE + 1;
	} while (!board.isValidMove(row-1, col-1));
	x = row - 1;
	y = col - 1;

	return true;
}

void Game::getOMove(char player, int &x, int &y) {
	if (noOfMoves >= 9) {
		return false;
	}

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!board.isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;

	return true;
}

void Game::play() {
    int player = 1;

	board.displayBoard();

	int done = 0;
	while (done == 0) {
		char playerSymbol = (player == 1) ? 'X' : 'O';
		cout << endl << "Player " << playerSymbol << " enter move: ";
		int x, y;

		if (player != -1) {
			getXMove(playerSymbol, x, y);
		} else {
			getOMove(playerSymbol, x, y);
		}

		board.addMove(x, y, player);
		
		noOfMoves++;
		
		board.displayBoard();

		done = board.gameStatus();
		if (done == 1) {
			cout << "Player X wins!" << endl;
			return 1;
		} else if (done == -1) {
			cout << "Player O wins!" << endl;
			return -1;
		} else if (done == 2) {
			cout << "Draw game!" << endl;
			return 0;
		}

		if (player == 1)
			player = -1;
		else
			player = 1;
	}

	return 0;
}

