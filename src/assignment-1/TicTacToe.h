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

const int BOARDSIZE = 3;

class TicTacToe {
private:
	int board[BOARDSIZE][BOARDSIZE];
	int noOfMoves;
	const int WIN = 3;
public:
	TicTacToe();
	bool isValidMove(int, int);
	bool getOMove(int&, int&);
	bool getXMove(int&, int&);
    vector<int> getCellValues();
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
	if (x >= 0 && x < BOARDSIZE && y >= 0 && y < BOARDSIZE) {
		// check if the cell is occupied
		if (board[x][y] == 1 || board[x][y] == -1) {
				cout << "error: cell is occupied" << endl;
				cout << "enter valid move:";
				return false;
			}
	} else {
		cout << "error: cell is not within range" << endl;
		cout << "enter valid move:";
		return false;
	}

	return true;
}

bool TicTacToe::getOMove(int &x, int &y) {
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

bool TicTacToe::getXMove(int &x, int &y) {
	if (noOfMoves >= 9) {
		return false;
	}

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

vector<int> TicTacToe::getCellValues() {
    vector<int> positions;

    for (int row = 0; row < BOARDSIZE; row++) {
        for (int col = 0; col < BOARDSIZE; col++) {
            positions.push_back(board[row][col]);
        }
    }

    return positions;
}

void TicTacToe::addMove(int x, int y, int player) {//What is this function for?
	board[x][y] = player;
}

int TicTacToe::gameStatus() {
	//Check rows for a win
	for (int row = 0; row < BOARDSIZE; row++) {
        int symbolCount = 0;

        for (int col = 0; col < BOARDSIZE; col++) {
            // access and process elements here
            if (board[row][col] == 1) {
                ++symbolCount;
                
                if (symbolCount == WIN) {
                    cout << "win found at position " << row + 1 << ", " << col + 1 << endl;
                    return 1;
                }
            } else {
                symbolCount = 0;
            }
        }
    }

	//Check columns for a win
	for (int col = 0; col < BOARDSIZE; col++) {
        int symbolCount = 0;

        for (int row = 0; row < BOARDSIZE; row++) {
            if (board[row][col] == 1) {
                ++symbolCount;
                
                if (symbolCount == WIN) {
                    cout << "win found at position " << col + 1 << ", " << row + 1 << endl;
                    return 1;
                }
            } else {
                symbolCount = 0;
            }
        }
    }

	//Check diagonals for a win

	// check top-left to bottom-right
	for (int row = 0; row <= BOARDSIZE - WIN; ++row) {
        for (int col = 0; col <= BOARDSIZE - WIN; ++col) {
            int symbolCount = 0;
            
            for (int i = 0; i < WIN; ++i) {
                if (board[row + i][col + i] == 1) {
                    ++symbolCount;
                    if (symbolCount == WIN) {
                        cout << "win found at position " << row + 1 << ", " << col + 1 << endl;
                        return 1;
                    }
                } else {
                    symbolCount = 0;
                }
            }
        }
    }

	// check top-right to bottom-left
	for (int row = 0; row <= BOARDSIZE - WIN; ++row) {
        for (int col = WIN - 1; col < BOARDSIZE; ++col) {
            int symbolCount = 0;
            
            for (int i = 0; i < WIN; ++i) {
                if (board[row + i][col - i] == 1) {
                    ++symbolCount;

                    if (symbolCount == WIN) {
                        cout << "win found at position " << col + 1 << ", " << row + 1 << endl;
                        return 1;
                    }
                } else {
                    symbolCount = 0;
                }
            }
        }
    }

	if (noOfMoves >= 9)
		return 2;

	return 0;
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