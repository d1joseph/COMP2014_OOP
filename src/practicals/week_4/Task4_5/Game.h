#ifndef GAME_H_
#define GAME_H_

class Game {
public:
    void play();
    void getXMove(int&, int&);
    void getOMove(int&, int&);
private:
    TicTacToe board;
};

void Game::getXMove(int& x, int& y) {
    cout << "calling Game::getXMove()" << endl;
    if (board.getMoveCount() >= 9) {
		return;
	}

	// rng seed
	std::srand(time(0));

	int row, col;
	do {
		row = rand() % 3 + 1;
		col = rand() % 3 + 1;
	} while (!board.isValidMove(row-1, col-1));
	x = row - 1;
	y = col - 1;
}

void Game::getOMove(int& x, int& y) {
    cout << "calling Game::getOMove()" << endl;
    if (board.getMoveCount() >= 9) {
		return;
    }

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!board.isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
}

void Game::play() {
    int player = 1;
    cout << "playing TicTacToe" << endl;
    
    board.displayBoard();
    
    int done = 0;
    while (done == 0) {
        char playerSymbol = (player == 1) ? 'X' : 'O';
        cout << endl << "Player" << playerSymbol << "enter move: ";
        
        int x, y;
        if (player != -1) {
            getXMove(x, y);
        } else {
            getOMove(x, y);
        }
        board.addMove(x, y, player);
        board.incrementMoves();
        board.displayBoard();

        done = board.gameStatus();
        if (done == 1) {
            cout << "Player X wins!" << endl;
        } else if (done = -1) {
            cout << "Player O wins!" << endl;
        } else if (done == 2) {
            cout << "Draw game!" << endl;
        }
        
        if (player == 1) {
            player = -1;
        } else {
            player = 1;
        }

    }
}

#endif // GAME_H_