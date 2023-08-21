//Functional implementation for basic Tic Tac Toe game (incomplete)

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayBoard(int board[][3]) {
	cout << "   1    2    3" << endl << endl;
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

bool isValidMove(int board[][3], int x, int y) {
	// check if the cell is within valid range
	if (x >= 0 && x < 3 && y >= 0 && y < 3) { //Add your code here)
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

bool getXOMove(int board[][3], int noOfMoves, int &x, int &y) {

	if (noOfMoves >= 9)
		return false;

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(board, row - 1, col - 1));
	x = row - 1;
	y = col - 1;

	return true;
}

void addMove(int board[][3], int x, int y, int player) {
	board[x][y] = player;
}

int gameStatus(int board[][3], int &noOfMoves) {
	//Write your code here to check if the game has been in a win status or a draw status
	const int boardSize = 3;
	const int win = 3;
	
	//Add your code here
	
	// check rows
	for (int row = 0; row < boardSize; row++) {
        int symbolCount = 0;

        for (int col = 0; col < boardSize; col++) {
            // access and process elements here
            if (board[row][col] == 1) {
                ++symbolCount;
                
                if (symbolCount == win) {
                    cout << "win found at position " << row << ", " << col << endl;
                    return 1;
                }
            } else {
                symbolCount = 0;
            }
        }
    }

	// check columns
	for (int col = 0; col < boardSize; col++) {
        int symbolCount = 0;

        for (int row = 0; row < boardSize; row++) {
            if (board[row][col] == 1) {
                ++symbolCount;
                
                if (symbolCount == win) {
                    cout << "win found at position " << col << ", " << row << endl;
                    return 1;
                }
            } else {
                symbolCount = 0;
            }
        }
    }

	// check top-left to bottom-right
	for (int row = 0; row <= boardSize - win; ++row) {
        for (int col = 0; col <= boardSize - win; ++col) {
            int symbolCount = 0;
            
            for (int i = 0; i < win; ++i) {
                if (board[row + i][col + i] == 1) { // Assuming you're looking for the value 1
                    ++symbolCount;
                    if (symbolCount == win) {
                        cout << "win found at position " << row << ", " << col << endl;
                        return 1;
                    }
                } else {
                    symbolCount = 0;
                }
            }
        }
    }

	// check top-right to bottom-left
	for (int row = 0; row <= boardSize - win; ++row) {
        for (int col = win - 1; col < boardSize; ++col) {
            int symbolCount = 0;
            
            for (int i = 0; i < win; ++i) {
                if (board[row + i][col - i] == 1) {
                    ++symbolCount;

                    if (symbolCount == win) {
                        cout << "win found at position " << col << ", " << row << endl;
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

int main() {
	int board[3][3];
	int noOfMoves;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;

	int player = 1;

	displayBoard(board);
	int done = 0;
	while (done == 0) {
		char playerSymbol = (player == 1) ? 'X' : 'O';
		cout << "Player " << playerSymbol << " enter move: ";
		int x, y;

		getXOMove(board, noOfMoves, x, y);

		addMove(board, x, y, player);
		noOfMoves++;
		displayBoard(board);

		done = gameStatus(board, noOfMoves);
		if (done == 1) {
			cout << "Player X wins!" << endl;
			return 0;
		} else if (done == -1) {
			cout << "Player O wins!" << endl;
			return 0;
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
