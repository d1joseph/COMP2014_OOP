#ifndef GAME_H_
#define GAME_H_

struct Coordinate {
    int x;
    int y;
};

class Game {
public:
    Game();
    void getXMove(int&, int&);
    void getOMove(int&, int&);
    void displayBoards();
    void play();
private:
    TicTacToe boards[3][3];
    Coordinate currentBoard;
};

Game::Game() {
    currentBoard.x = 0;
    currentBoard.y = 0;
}

void Game::getXMove(int& x, int& y) {
    cout << "calling Game::getXMove()" << endl;
    if (boards[0][0].getMoveCount() >= 9) {
		return;
	}

	// rng seed
	std::srand(time(0));

	int row, col;
	do {
		row = rand() % 3 + 1;
		col = rand() % 3 + 1;
	} while (!boards[0][0].isValidMove(row-1, col-1));
	x = row - 1;
	y = col - 1;
}

void Game::getOMove(int& x, int& y) {
    cout << "calling Game::getOMove()" << endl;
    if (boards[0][0].getMoveCount() >= 9) {
		return;
    }

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!boards[0][0].isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
}

void Game::play() {
    int player = 1;
    cout << "playing TicTacToe" << endl;
    
    displayBoards();
    
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
        boards[0][0].addMove(x, y, player);
        boards[0][0].incrementMoves();
        displayBoards();

        done = boards[0][0].gameStatus();
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

void Game::displayBoards() {
    for (int row = 0; row < 3; row++) {
        for (int i = 0; i < 3; i++) {
            for (int col = 0; col < 3; col++) {
                for (int j = 0; j < 3; j++) {                 
                    
                    vector<int> positions = boards[row][col].getCells();

                    char playerSymbol = ' ';
                    if (positions[i * 3 + j] == 1) {
                        playerSymbol = 'X';
                    } else if (positions[i * 3 + j] == -1) {
                        playerSymbol = 'O';
                    }

                    if (j == 0) {
                        cout << " ";   
                    }
                    
                    cout << "|" << playerSymbol;
                    
                    if (j == 2) {
                        cout << "|";
                    }
                }

                if (col < 3 - 1) {
                    cout << "  ";
                }    
            }
            cout << endl;
        }

        if (row < 3 - 1) {
            for (int i = 0; i < 28; i++) {
                cout << "-";
            }
            cout << endl;
        }
    }
}

#endif // GAME_H_