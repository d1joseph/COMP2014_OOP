/*
 * SmartPlayer.h
 *
 *  Created on: 24 Jul. 2020
 *      Author: dongmo
 */

#ifndef MINDFULPLAYER_H_
#define MINDFULPLAYER_H_

class MindfulPlayer: public Player {
public:
	MindfulPlayer(char p) :
			Player(p) {
	}
	~MindfulPlayer() {
	}

	void getMove(TicTacToe board, int& x, int& y) {
		vector<int> emptyCells = board.getEmptyPositions();
		if (emptyCells.empty())
			return;

		for (int index : emptyCells) {
			int i = index / 3;
			int j = index % 3;
			TicTacToe tempBoard = TicTacToe(board);

			x = i;
			y = j;

			tempBoard.addMove(playerSymbol, i, j);
			if (tempBoard.gameStatus() == playerSymbol) {
				return;
			}

			if (tempBoard.threatenLevel(playerSymbol) == 2)
				continue;

		}

		return;
	}

};

#endif /* MINDFULPLAYER_H_ */
