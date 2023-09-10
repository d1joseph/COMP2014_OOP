#ifndef NBTICTACTOE_H_
#define NBTICTACTOE_H_

struct Coordinate {
    int x;
    int y;
};

struct Move {
    int row;
    int col;
};

class NBTicTacToe {
private:
    TicTacToe boards[3][3];
    Coordinate currentBoard;
    char playerSymbol;
public:
    NBTicTacToe(HumanPlayer, RandomPlayer);
    void displayBoards();
    void displayGameInfo(int&, int&, int&, int&, int&);
    void getCurrentBoard(int&, int&);
    void getCurrentTurn(int&, char&);
    void getPreviousMovePlayed(int&, int&);
    void getRules();
    int play(HumanPlayer, RandomPlayer);
    void getMovePlayed(int&, int&, char&);
    void setCurrentBoard(int&, int&, int&);
};

NBTicTacToe::NBTicTacToe(HumanPlayer, RandomPlayer) {
    cout << "##OXO Nine Board to Board TicTacToe XOX##" << endl;
    srand(time(0));
    int x = rand() % 3;
    int y = rand() % 3;
    currentBoard.x = x;
    currentBoard.y = y;

    HumanPlayer human;
    RandomPlayer random;
}

int NBTicTacToe::play(HumanPlayer human, RandomPlayer random) {
    // getRules();
    int player = 1;

    displayBoards();

    // last move played
    Move lastMovePlayed;

    int done = 0;
    while (done == 0) {
        playerSymbol = (player == 1) ? 'X' : 'O';
        int x, y;

        if (player == 1) {
            random.getXMove(boards[currentBoard.x][currentBoard.y], x, y, playerSymbol);
            // human.getOMove(boards[currentBoard.x][currentBoard.y], x, y, playerSymbol);
            lastMovePlayed.row = x;
            lastMovePlayed.col = y;
        } else {
            human.getOMove(boards[currentBoard.x][currentBoard.y], x, y, playerSymbol);
            lastMovePlayed.row = x;
            lastMovePlayed.col = y;
        }

        boards[currentBoard.x][currentBoard.y].addMove(x, y, player);
        
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

        setCurrentBoard(x, y, player);

        displayGameInfo(player, x, y, lastMovePlayed.row, lastMovePlayed.col);
        
        if (player == 1) {
            player = -1;
        } else {
            player = 1;
        }       
    }

    return 0;
}

void NBTicTacToe::getCurrentBoard(int& x, int& y) {
    cout << "event: playing board(" << x + 1 << ","
    << y + 1 << ")" << endl;
}

void NBTicTacToe::getCurrentTurn(int& player, char& playerSymbol) {
    char currentSymbol = (player != 1) ? 'X' : 'O';
    cout << "current turn: player " << currentSymbol << endl;
}

void NBTicTacToe::getRules() {
    
}

void NBTicTacToe::getMovePlayed(int& x, int& y, char& player) {
	cout << "event: " << player << " plays move: (" << x + 1 << ","
	<< y + 1 << ")" << endl;
}

void NBTicTacToe::getPreviousMovePlayed(int& x, int& y) {
    cout << "last move played: (" << (x + 1) << "," << (y + 1) << ")" << endl;
}

void NBTicTacToe::displayBoards() {
    cout << endl << endl;
    // TODO: Add row/column numbers
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

void NBTicTacToe::displayGameInfo(int& player, int& x, int& y, int& lastX, int& lastY) {
    getMovePlayed(x, y, playerSymbol);
    getCurrentBoard(currentBoard.x, currentBoard.y);
    getPreviousMovePlayed(lastX, lastY);
    getCurrentTurn(player, playerSymbol);
    
    // 4. print number of turns left at last board played
    // 5. print number of turns left in focus board
    // 6. if done != 0 print the game summary
}

void NBTicTacToe::setCurrentBoard(int& x, int& y, int& player) {
    currentBoard.x = x;
    currentBoard.y = y;
}

#endif // NBTICTACTOE_H_