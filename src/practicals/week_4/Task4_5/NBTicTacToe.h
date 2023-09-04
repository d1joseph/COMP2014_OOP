#ifndef NBTICTACTOE_H_
#define NBTICTACTOE_H_

#include "TicTacToe.h"
#include <iostream>

struct Coordinate {
	int x;
	int y;
};

class NBTicTacToe {
public:
	// NBTicTacToe constructor
	NBTicTacToe(int x, int y) {
		currentBoard.x = x;
		currentBoard.y = y;
	};

	void play();
	void getXMove(char player, int&, int&);
	void getOMove(char player, int&, int&);
	void switchBoard(int, int);
	void displayBoard();
private:
	TicTacToe grid[3][3]; // 2d array of TicTacToe instances
	Coordinate currentBoard;
};

void NBTicTacToe::getXMove(char player, int &row, int &col) {
	// rng seed
	std::srand(time(0));
    
	int r, c;
	do {
		r = rand() % 3 + 1;
		c = rand() % 3 + 1;
	} while (!grid[currentBoard.x][currentBoard.y].isValidMove(r-1, c-1));
	row = r;
	col = c;
}

void NBTicTacToe::getOMove(char player, int &row, int &col) {
	do {
		std::cout << "Player " << player << " enter move: ";
		std::cin >> row >> col;
		std::cout << std::endl;
	} while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));

	row--;
	col--;
}

void NBTicTacToe::switchBoard(int x, int y) {
	currentBoard.x = x;
	currentBoard.y = y;
}

void NBTicTacToe::displayBoard() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char symbol;

			if (grid[i][j] == 'X')
				symbol = 'X';
			else if (grid[i][j] == 'O')
				symbol = 'O';
			else
				symbol = '_';
			
			cout << symbol;			
			if ((j+1) % 3 == 0) {
				cout << " ";
			}
		}
		cout << endl;
		if ((i+1) % 3 == 0) {
			cout << endl;
		}
	}
}

void NBTicTacToe::play() {
	bool done = false;
	char player = 'X';
	
	displayBoard();
	while (!done) {
		int row, col;

		std::cout << "current board: [" << currentBoard.x << "]"
		<< "[" << currentBoard.y << "]" << std::endl;
		if (player == 'X') {
			// rng seed
			std::srand(time(0));
			
			// choose a random board to play at beginning of X turn
			int randX = std::rand() % 3;
			int randY = std::rand() % 3;
			switchBoard(randX, randY);

			getXMove(player, row, col);
		}
		else {
			getOMove(player, row, col);
		}

		done = grid[currentBoard.x][currentBoard.y].addMove(player, row, col);
		displayBoard();

		if (player == 'X')
			player = 'O';
		else	
			player = 'X';
	}
}

#endif // NBTICTACTOE_H_
