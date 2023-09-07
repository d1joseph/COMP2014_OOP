#ifndef GAME_H_
#define GAME_H_

#include "TicTacToe.h"
#include <iostream>

class Game {
public:
	void play();
	void getXMove(char player, int&, int&);
	void getOMove(char player, int&, int&);
private:
	TicTacToe board;
};

void Game::getXMove(char player, int& row, int& col) {
	// rng seed
	std::srand(time(0));

	int r, c;
	do {
		r = rand() % 3 + 1;
		c = rand() % 3 + 1;
	} while (!board.isValidMove(r-1, c-1));
	row = r - 1;
	col = c - 1;

}

void Game::getOMove(char player, int& row, int& col) {
	do {
		std::cout << "Player " << player << " enter move: ";
		std::cin >> row >> col;
		std::cout << std::endl;
	} while (!board.isValidMove(row - 1, col - 1));

	row--;
	col--;
}

void Game::play() {
	bool done = false;
	char player = 'X';

	board.displayBoard();

	while (!done) {
		int row, col;
		if (player == 'X')
			getXMove(player, row, col);
		else
			getOMove(player, row, col);

		done = board.addMove(player, row, col);

		board.displayBoard();

		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}
}

#endif // GAME_H_
