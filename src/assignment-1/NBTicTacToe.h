/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/
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
    void displayBoards();
    int play();
};

int NBTicTacToe::play() {
    cout << "### 9 Board Tic Tac Toe ###" << endl << endl;
    
    int player = 1; // x goes first
    HumanPlayer human;
    RandomPlayer random;
    
    displayBoards();
    
    int done = 0;
    while (done == 0) {
        srand(time(0));

        char playerSymbol = (player == 1) ? 'X' : 'O';
        cout << "Player " << playerSymbol << " enter move[row][col]: ";

        int x, y;
        if (player != -1) {
            int x = rand() % 3;
            int y = rand() % 3;
            // choose a board to play using currentBoard struct;
            currentBoard.x = x;
            currentBoard.y = y;
            cout << endl << "Player X set focus board to board[" << currentBoard.x + 1
            << "]" << "[" << currentBoard.y + 1 << "]" << endl;
            
            random.getXMove(boards[currentBoard.x][currentBoard.y], x, y);
        } else {
            human.getOMove(boards[currentBoard.x][currentBoard.y], x, y);
        }

        cout << endl << "playing board[" << currentBoard.x + 1 << "]"
        << "[" << currentBoard.y + 1 << "]" << endl;

        // add move and increment for focus board
        boards[currentBoard.x][currentBoard.y].addMove(x, y, player);
        boards[currentBoard.x][currentBoard.y].incrementMoveCount();
        
        displayBoards(); // show latest state of boards

        done = boards[currentBoard.x][currentBoard.y].gameStatus();
        if (done == 1) {
            cout << "Player X wins board[" << currentBoard.x << "]" << "["
            << currentBoard.y << "]" << endl;
            return 1;
        } else if (done == -1) {
            cout << "Player O wins board[" << currentBoard.x << "]" << "["
            << currentBoard.y << "]" << endl;
            return -1;
        } else if (done == 2) {
            cout << "Draw game at board[" << currentBoard.x << "]" << "["
            << currentBoard.y << "]" << endl;
            return 0;
        }

        if (player == 1) {
            player = -1;
        } else {
            player = 1;
        }

    }

    return 0;
}

void NBTicTacToe::displayBoards() {
    for (int row = 0; row < 3; row++) {
        for (int i = 0; i < 3; i++) { // loop for each row in the board
            for (int col = 0; col < 3; col++) {
                for (int j = 0; j < 3; j++) { // loop for each cell in a row                    
                    
                    // get cell values for each board instance
                    vector<int> positions = boards[row][col].getCellValues();

                    char playerSymbol = ' ';
                    if (positions[i * 3 + j] == 1) {
                        playerSymbol = 'X';
                    } else if (positions[i * 3 + j] == -1) {
                        playerSymbol = 'O';
                    }
                    
                    // cell borders
                    if (j == 0) {
                        cout << " ";   
                    }
                    
                    cout << "|" << playerSymbol;
                    
                    if (j == 2) {
                        cout << "|";
                    }
                }

                if (col < 3 - 1) {
                    cout << "  "; // padding between boards
                }    
            }
            cout << endl;
        }

        // row dividers
        if (row < 3 - 1) {
            for (int i = 0; i < 28; i++) {
                cout << "-";
            }
            cout << endl;
        }
    }
}
#endif // NBTICTACTOE_H_