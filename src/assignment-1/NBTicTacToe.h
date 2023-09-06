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
    cout << "calling NBTicTacToe::play()" << endl;

    displayBoards();

    return 0;
}

void NBTicTacToe::displayBoards() {
    cout << "calling NBTicTacToe::displayBoards()" << endl << endl;

    for (int row = 0; row < BOARDSIZE; row++) {
        for (int i = 0; i < BOARDSIZE; i++) { // loop for each row in the board
            for (int col = 0; col < BOARDSIZE; col++) {
                for (int j = 0; j < BOARDSIZE; j++) { // loop for each cell in a row                    
                    
                    // get cell values for each board instance
                    vector<int> positions = boards[row][col].getCellValues();

                    char playerSymbol = ' ';
                    if (positions[i * BOARDSIZE + j] == 1) {
                        playerSymbol = 'X';
                    } else if (positions[i * BOARDSIZE + j] == -1) {
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

                if (col < BOARDSIZE - 1) {
                    cout << "  "; // padding between boards
                }    
            }
            cout << endl;
        }

        // row dividers
        if (row < BOARDSIZE - 1) {
            for (int i = 0; i < 28; i++) {
                cout << "-";
            }
            cout << endl;
        }
    }
}
#endif // NBTICTACTOE_H_