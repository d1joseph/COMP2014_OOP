/*
 * TicTacToe.h
 *
 *  Created on: 5 Aug 2023
 *      Author: 2002345
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

const int BOARDSIZE = 3;

class TicTacToe {
private:
	int board[BOARDSIZE][BOARDSIZE];
	int noOfMoves;
public:
	TicTacToe();
	bool isValidMove(int, int);
	bool getXOMove(int&, int&);
	bool getXMove(int&, int&);
	bool getOMove(int&, int&);
	void addMove(int, int, int);
	int gameStatus();
	int play();
	void displayBoard();
};

TicTacToe::TicTacToe() {//How to call this function?
	/*
		A: constructor for TicTacToe, call wherever we want to
		instantiate the game board object e.g. int main {TicTacToe tictactoe; return 0;}
	*/
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}

void TicTacToe::displayBoard() {//Where to get the board data?
	/*
		A: the board data is iniatilised with 0 values when we call the constructor,
		the board is represented as a 2d array (array of arrays) with the value of 
		each cell accessed by its 2 indexes; board[i][j] to get the current value 
		stored by iterating through the boardusing a nested for loop.
	*/
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

bool TicTacToe::isValidMove(int x, int y) {//Add your code to complete the program
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

bool TicTacToe::getOMove(int &x, int &y) {//What does & mean?
	/*
		A: address-of operator used to define a call-by reference parameter
	*/

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

	// rng seed
	std::srand(time(0));

	int row, col;
	do {
		row = rand() % BOARDSIZE + 1;
		col = rand() % BOARDSIZE + 1;
	} while (!isValidMove(row-1, col-1));
	x = row - 1;
	y = col - 1;

	return true;
}

void TicTacToe::addMove(int x, int y, int player) {//What is this function for?
	/*
		A: adds the current player's 'X' or 'O' marker represented by a 1 or -1 to that
		player's chosen cell at position x, y, can only be used if TicTacToe.isValidMove() 
		returns true
	*/
	board[x][y] = player;
}

int TicTacToe::gameStatus() {//Add your code to complete the program
	//Write your code here to check if the game has been in a win status or a draw status

	//Check rows for a win
	

	//Add your code here

	//Check columns for a win

	//Add your code here

	//Check diagonals for a win

	//Add your code here

	if (noOfMoves >= 9)
		return 2;

	return 0;
}

int TicTacToe::play() {//What is the counterpart of this function in the original code
	/*
		A: The main() function in Task3_2n3.cpp
	*/
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
