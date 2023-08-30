#include "TicTacToe.h"
#include <iostream>

using namespace std;

class Game {
public:
    void play();
    void getXMove(char player, int&, int&);
    void getOMove(char player, int&, int&);
private:
    TicTacToe board;
};

void getXMove(char player, int &x, int &y) {
    if (noOfMoves >= 9) {
		return false;
	}

	// rng seed
	srand(time(0));

	int row, col;
	do {
		row = rand() % BOARDSIZE + 1;
		col = rand() % BOARDSIZE + 1;
	} while (!isValidMove(row-1, col-1));
	x = row - 1;
	y = col - 1;

	return true;
}

void getOMove(char player, int &x, int &y) {
    
	if (noOfMoves >= 9)
		return false;

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;

	return true;
}

void play() {
    int player = 1;

	TicTacToe::displayBoard();
	int done = 0;
	while (done == 0) {
		char playerSymbol = (player == 1) ? 'X' : 'O';
		cout << endl << "Player " << playerSymbol << " enter move: ";
		int x, y;

		if (player != -1) {
			getXMove(x, y);
		} else {
			getOMove(x, y);
		}

		addMove(x, y, player);
		noOfMoves++;
		displayBoard();

		done = gameStatus();
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

