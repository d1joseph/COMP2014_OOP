//Tic-Tac-Toe Header file

class ticTacToe {
public:
	ticTacToe(const ticTacToe& cboard) {
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				board[row][col] = cboard.board[row][col];
		player = cboard.player;
		noOfMoves = cboard.noOfMoves;
	}

	char getPlayer() {
		return player;
	}

	bool isFull() {
		return (noOfMoves >= 9);
	}

	int getNoOfMoves() {
		return noOfMoves;
	}

	void displayBoard() const;
	//Function to print the board.

	bool isValidMove(int x, int y) const;
	//Function to determine if a move is valid.

	void addMove(int x, int y);
	//Function to get a move for a player

	vector<int> getEmptyPositions();
	//Function to get empty positions

	void getaRandomMove(int& x, int& y);
	//Function to get a valid random move

	char gameStatus();
	//Function to determine the current status of the game.

	ticTacToe();
	//Default constructor.
	//Postcondition: Initializes the board to an empty state.

private:
	char board[3][3];
	char player;
	int noOfMoves;
};

void ticTacToe::displayBoard() const {
	cout << "   1    2    3" << endl << endl;

	for (int row = 0; row < 3; row++) {
		cout << row + 1;

		for (int col = 0; col < 3; col++) {
			cout << setw(3) << board[row][col];

			if (col != 2)
				cout << " |";
		}

		cout << endl;

		if (row != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}

	cout << endl;
}

bool ticTacToe::isValidMove(int row, int col) const {
	if (0 <= row && row <= 2 && 0 <= col && col <= 2 && board[row][col] == ' ')
		return true;
	else
		return false;
}

void ticTacToe::addMove(int x, int y) {
	if(!isValidMove(x,y))
		return;

	board[x][y] = player;
	player = (player == 'X') ? 'O' : 'X';
	noOfMoves++;
}

vector<int> ticTacToe:: getEmptyPositions() {
	vector<int> emptyCells;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ')
				emptyCells.push_back(i * 3 + j);
		}
	}
    return emptyCells;
}

void ticTacToe::getaRandomMove(int& x, int& y) {
	vector<int> emptyCells = getEmptyPositions();

	int index = rand() % emptyCells.size();
	x = emptyCells[index] / 3;
	y = emptyCells[index] % 3;
}

char ticTacToe::gameStatus() {
	//Check rows for a win
	for (int row = 0; row < 3; row++)
		if (board[row][0] != ' ' && (board[row][0] == board[row][1])
				&& (board[row][1] == board[row][2]))
			return board[row][0];

	//Check columns for a win
	for (int col = 0; col < 3; col++)
		if (board[0][col] != ' ' && (board[0][col] == board[1][col])
				&& (board[1][col] == board[2][col]))
			return board[0][col];

	//Check diagonals for a win
	if (board[0][0] != ' ' && (board[0][0] == board[1][1])
			&& (board[1][1] == board[2][2]))
		return board[0][0];

	if (board[2][0] != ' ' && (board[2][0] == board[1][1])
			&& (board[1][1] == board[0][2]))
		return board[2][0];

	if (noOfMoves < 9)
		return 'C';

	return 'D';
}

ticTacToe::ticTacToe() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	player = 'X';
	noOfMoves = 0;
}

