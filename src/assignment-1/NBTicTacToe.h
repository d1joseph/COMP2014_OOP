#ifndef NBTICTACTOE_H_
#define NBTICTACTOE_H_

struct Coordinate {
    int x;
    int y;
};

class NBTicTacToe {
private:
    TicTacToe boards[3][3];
    Coordinate currentBoard;
public:
    NBTicTacToe(HumanPlayer, RandomPlayer);
    bool start();
    int play(HumanPlayer, RandomPlayer);
    void displayBoards();
    void indicateCurrent(int&, int&);
    void printMovePlayed(int&, int&, char);
    void setFocus();

    void displayData();
};

NBTicTacToe::NBTicTacToe(HumanPlayer, RandomPlayer) {
    int x = rand() % 3;
    int y = rand() % 3;
    currentBoard.x = x;
    currentBoard.y = y;

    cout << "### Welcome to Board Tic Tac Toe ###" << endl;

    HumanPlayer human;
    RandomPlayer random;
}

int NBTicTacToe::play(HumanPlayer human, RandomPlayer random) {
    int player = 1;
    // HumanPlayer human;
    // RandomPlayer random;

    displayBoards();
    int done = 0;
    while (done == 0) {
        char playerSymbol = (player == 1) ? 'X' : 'O';
        int x, y;
        
        cout << endl << "event: player " << playerSymbol  << " sets focus to board(" << currentBoard.x + 1
        << "," << currentBoard.y + 1 << ")" << endl;
        
        indicateCurrent(currentBoard.x, currentBoard.y);
        cout << "event: player " << playerSymbol << " turn" << endl;
        
        if (player == 1) {
            random.getXMove(boards[currentBoard.x][currentBoard.y], x, y, playerSymbol);
            // human.getOMove(boards[currentBoard.x][currentBoard.y], x, y, playerSymbol);

        } else {
            human.getOMove(boards[currentBoard.x][currentBoard.y], x, y, playerSymbol);
        }

        boards[currentBoard.x][currentBoard.y].addMove(x, y, player);
        
        printMovePlayed(x, y, playerSymbol);
        
        boards[currentBoard.x][currentBoard.y].incrementMoveCount();

        displayBoards();
        
        done = boards[currentBoard.x][currentBoard.y].gameStatus();
        if (done == 1) {
            cout << "event: Player X wins board[" << currentBoard.x + 1 << "]" << "["
            << currentBoard.y + 1 << "]" << endl;
            return 1;
        } else if (done == -1) {
            cout << "event: Player O wins board[" << currentBoard.x + 1 << "]" << "["
            << currentBoard.y + 1 << "]" << endl;
            return -1;
        } else if (done == 2) {
            cout << "event: Draw game at board[" << currentBoard.x + 1 << "]" << "["
            << currentBoard.y + 1 << "]" << endl;
            return 0;
        }

        currentBoard.x = x;
        currentBoard.y = y;
        
        if (player == 1) {
            player = -1;
        } else {
            player = 1;
        }       
    }

    return 0;
}

void NBTicTacToe::indicateCurrent(int& x, int& y) {
    cout << "event: playing board(" << x + 1 << ","
    << y + 1 << ")" << endl;
}

void NBTicTacToe::printMovePlayed(int& x, int& y, char player) {
	cout << "event: player " << player << " plays move: (" << x + 1 << ","
	<< y + 1 << ")" << endl;
}

void NBTicTacToe::displayBoards() {
    for (int row = 0; row < 3; row++) {
        for (int i = 0; i < 3; i++) {
            for (int col = 0; col < 3; col++) {
                for (int j = 0; j < 3; j++) {                 
                    
                    vector<int> positions = boards[row][col].getCellValues();

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
#endif // NBTICTACTOE_H_