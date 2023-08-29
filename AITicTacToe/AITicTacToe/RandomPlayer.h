/*
 * RandomPlayer.h
 *
 *  Created on: 22 Mar. 2019
 *      Author: dongmo
 */

#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

class RandomPlayer : public Player {
public:
	RandomPlayer(char ps):Player(ps) {}
	~RandomPlayer(){}

	void getMove(TicTacToe board, int& x, int& y) {
		vector<int> emptyCells;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board.getGrid(i, j) == ' ')
					emptyCells.push_back(i * 3 + j);
			}
		}
		int index = rand() % emptyCells.size();
		x = emptyCells[index] / 3;
		y = emptyCells[index] % 3;
		return;
	}
};

#endif /* RANDOMPLAYER_H_ */
