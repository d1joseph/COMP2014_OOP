/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/
#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

class Human {
public:
    void getOMove(TicTacToe board, int&, int&);
}

void Human::getOMove(TicTacToe board, int& x, int& y) {
    if (board.getMoveCount() >= 9)
		return;

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!board.isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
}

#endif // HUMANPLAYER_H_