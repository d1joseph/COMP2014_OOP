/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/

#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

class RandomPlayer {
public:
    void getXMove(TicTacToe board, int&, int&, char);
};

// board passed as TicTacToe board[currentBoard.x][currentBoard.y]
void RandomPlayer::getXMove(TicTacToe board, int& x, int& y, char playerSymbol) {
    if (board.getMoveCount() >= 9) {
        return;
	}

	do {
		x = rand() % 3;
		y = rand() % 3;
	} while (!board.isValidMove(x, y));
};

#endif // RANDOMPLAYER_H_