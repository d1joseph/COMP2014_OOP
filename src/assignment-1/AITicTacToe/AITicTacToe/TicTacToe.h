//Tic-Tac-Toe Header file

class TicTacToe {
public:
	TicTacToe(const TicTacToe& cboard) {
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				board[row][col] = cboard.board[row][col];

		noOfMoves = cboard.noOfMoves;
	}

	char getGrid(int i, int j) {
		return board[i][j];
	}

	bool isFull() {
		return (noOfMoves >= 9);
	}
	void displayBoard() const;

	bool isValidMove(int x, int y) const;

	void addMove(char moveSymbol, int x, int y);

	char gameStatus();

	void reStart();

	TicTacToe();

	int threatenLevel(char playerId);

	vector<int> getEmptyPositions();
	void getaRandomMove(int& x, int& y);

private:
	char board[3][3];
	int noOfMoves;
};

void TicTacToe::displayBoard() const {
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

bool TicTacToe::isValidMove(int row, int col) const {
	if (0 <= row && row <= 2 && 0 <= col && col <= 2 && board[row][col] == ' ')
		return true;
	else
		return false;
}

void TicTacToe::addMove(char playerSymbol, int x, int y) {
	if(!isValidMove(x,y))
		return;

	board[x][y] = playerSymbol;

	noOfMoves++;
}

char TicTacToe::gameStatus() {
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

void TicTacToe::getaRandomMove(int& x, int& y) {
	vector<int> emptyCells = getEmptyPositions();

	int index = rand() % emptyCells.size();
	x = emptyCells[index] / 3;
	y = emptyCells[index] % 3;
}

vector<int> TicTacToe:: getEmptyPositions() {
	vector<int> emptyCells;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ')
				emptyCells.push_back(i * 3 + j);
		}
	}
	random_shuffle(emptyCells.begin(), emptyCells.end());

    return emptyCells;
}

void TicTacToe::reStart() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	noOfMoves = 0;
}

TicTacToe::TicTacToe() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	noOfMoves = 0;
}

int TicTacToe::threatenLevel(char playerId) {
	int max = 0;
	char opponent = playerId == 'X'?'O':'X';
	for (int row = 0; row < 3; row++) {
		int counter = 0;
		for (int col = 0; col < 3; col++) {
			if (board[row][col] == playerId) {
				counter = 0;
				break;
			} else if (board[row][col] == opponent)
				counter++;
		}
		if (counter > max)
			max = counter;
	}

	for (int col = 0; col < 3; col++) {
		int counter = 0;
		for (int row = 0; row < 3; row++) {
			if (board[row][col] == playerId) {
				counter = 0;
				break;
			} else if (board[row][col] == opponent)
				counter++;
		}
		if (counter > max)
			max = counter;
	}

	int counter = 0;
	for (int k = 0; k < 3; k++) {
		if (board[k][k] == playerId) {
			counter = 0;
			break;
		} else if (board[k][k] == opponent)
			counter++;
	}
	if (counter > max)
		max = counter;

	counter = 0;
	for (int k = 0; k < 3; k++) {
		if (board[k][2-k] == playerId) {
			counter = 0;
			break;
		} else if (board[k][2-k] == opponent)
			counter++;
	}
	if (counter > max)
		max = counter;

    return max;
}
