/*
 * Game.h
 *
 *  Created on: 22 Mar. 2019
 *      Author: dongmo
 */

#ifndef GAME_H_
#define GAME_H_

class Game {
public:
	void play() {
		Board board;
		board.displayBoard();

		HumanPlayer hplayer;
		MonteCarloPlayer mplayer('O');

		while (true) {
			int x, y;

			hplayer.getMove(board, x, y);
			board.addMove(x, y);
			cout << "X makes a move (" << (x + 1) << "," << (y + 1) << ") "
					<< endl;
			board.displayBoard();
			if (checkWin('X', board))
				break;

			mplayer.getMove(board, x, y);
			board.addMove(x, y);
			cout << "O makes a move (" << (x + 1) << "," << (y + 1) << ") "
					<< endl;
			board.displayBoard();
			if (checkWin('O', board))
				break;
		}
	}

	bool checkWin(char playerSymbol, Board board) {
		char gStatus = board.gameStatus();

		if (gStatus == playerSymbol) {
			cout << "Player " << playerSymbol << " wins!" << endl;
			return true;
		} else if (gStatus == 'D') {
			cout << "This game is a draw!" << endl;
			return true;
		} else if (gStatus != 'C') {
			return true;
		} else
			return false;
	}
};

#endif /* GAME_H_ */
