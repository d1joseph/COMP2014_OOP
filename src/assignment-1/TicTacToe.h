/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/
#ifndef TICTACTOE_H_
#define TICTACTOE_H_

class TicTacToe {
private:
	int board[3][3];
	int noOfMoves;
	const int WIN = 3;
public:
	TicTacToe();
	bool isValidMove(int, int);
	bool getOMove(int&, int&);
	bool getXMove(int&, int&);
    vector<int> getCellValues();
	int getMoveCount();
	void incrementMoveCount();
	void addMove(int, int, int);
	int gameStatus();
	int play();
	void displayBoard();
};

TicTacToe::TicTacToe() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}

void TicTacToe::displayBoard() {
	cout << endl << "   1    2    3" << endl << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1;
		for (int j = 0; j < 3; j++) {
			char playerSymbol = ' ';
			if (board[i][j] == 1)
				playerSymbol = 'X';
			else if (board[i][j] == -1)
				playerSymbol = 'O';
			cout << setw(3) << playerSymbol;
			if (j != 2)
				cout << " |";
		}
		cout << endl;
		if (i != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}
	cout << endl;
}

bool TicTacToe::isValidMove(int x, int y) {
	if (0 <= x && x <= 2 && 0 <= y && y <= 2 && board[x][y] == 0) {
		return true;
	}
	else {
		cout << "warning: invalid move" << endl;
		cout << "input: enter a valid move:";
		return false;
	}
}

bool TicTacToe::getOMove(int& x, int& y) {
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

bool TicTacToe::getXMove(int& x, int& y) {
	if (noOfMoves >= 9) {
		return false;
	}

	srand(time(0));

	int row, col;
	do {
		row = rand() % 3 + 1;
		col = rand() % 3 + 1;
	} while (!isValidMove(row-1, col-1));
	x = row - 1;
	y = col - 1;

	return true;
}

vector<int> TicTacToe::getCellValues() {
    vector<int> positions;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            positions.push_back(board[row][col]);
        }
    }

    return positions;
}

int TicTacToe::getMoveCount() {
	return noOfMoves;
}

void TicTacToe::incrementMoveCount() {
	noOfMoves++;
}

void TicTacToe::addMove(int x, int y, int player) {
	board[x][y] = player;
}

int TicTacToe::gameStatus() {
    for (int player = 1; player >= -1; player -= 2) {
        int winSymbol = player;

        // Check rows for a win
        for (int row = 0; row < 3; row++) {
            int symbolCount = 0;

            for (int col = 0; col < 3; col++) {
                if (board[row][col] == winSymbol) {
                    ++symbolCount;

                    if (symbolCount == WIN) {
                        return winSymbol;
                    }
                } else {
                    symbolCount = 0;
                }
            }
        }

        // Check columns for a win
        for (int col = 0; col < 3; col++) {
            int symbolCount = 0;

            for (int row = 0; row < 3; row++) {
                if (board[row][col] == winSymbol) {
                    ++symbolCount;

                    if (symbolCount == WIN) {
                        return winSymbol;
                    }
                } else {
                    symbolCount = 0;
                }
            }
        }

        // Check diagonals for a win

        // Check top-left to bottom-right
        for (int row = 0; row <= 3 - WIN; ++row) {
            for (int col = 0; col <= 3 - WIN; ++col) {
                int symbolCount = 0;

                for (int i = 0; i < WIN; ++i) {
                    if (board[row + i][col + i] == winSymbol) {
                        ++symbolCount;

                        if (symbolCount == WIN) {
                            return winSymbol;
                        }
                    } else {
                        symbolCount = 0;
                    }
                }
            }
        }

        // Check top-right to bottom-left
        for (int row = 0; row <= 3 - WIN; ++row) {
            for (int col = WIN - 1; col < 3; ++col) {
                int symbolCount = 0;

                for (int i = 0; i < WIN; ++i) {
                    if (board[row + i][col - i] == winSymbol) {
                        ++symbolCount;

                        if (symbolCount == WIN) {
                            return winSymbol;
                        }
                    } else {
                        symbolCount = 0;
                    }
                }
            }
        }
    }

    if (noOfMoves >= 9) {
        return 2; // Draw
    }

    return 0; // Game still in progress
}

int TicTacToe::play() {
	int player = 1;

	displayBoard();
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

#endif /* TICTACTOE_H_ */