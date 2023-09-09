#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

class RandomPlayer {
public:
    void getXMove(TicTacToe board, int&, int&, char);
};

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