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

class HumanPlayer {
public:
    void getOMove(TicTacToe board, int&, int&, char);
};

// board passed as TicTacToe board[currentBoard.x][currentBoard.y]
void HumanPlayer::getOMove(TicTacToe board, int& x, int& y, char playerSymbol) {
    if (board.getMoveCount() >= 9) {
		return;
	}

	cout << "input: player " << playerSymbol << " enter move[row][col]: ";
	do {
		cin >> x >> y;
		cout << endl;
	} while (!board.isValidMove(x - 1, y - 1));
	x = x - 1;
	y = y - 1;
};

#endif // HUMANPLAYER_H_