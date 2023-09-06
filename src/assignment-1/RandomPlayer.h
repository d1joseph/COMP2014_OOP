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
    void getXMove(TicTacToe board, int&, int&);
}

void RandomPlayer::getXMove(TicTacToe, int&, int&) {
    if (board.getMoveCount() >= 9) {
        return;
	}

	srand(time(0));

	int row, col;
	do {
		row = rand() % BOARDSIZE + 1;
		col = rand() % BOARDSIZE + 1;
	} while (!board.isValidMove(row-1, col-1));
	x = row - 1;
	y = col - 1;
}

#endif // RANDOMPLAYER_H_