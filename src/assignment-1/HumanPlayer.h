#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

class HumanPlayer {
public:
    void getOMove(TicTacToe board, int&, int&, char);
};

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