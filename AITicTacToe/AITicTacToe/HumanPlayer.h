/*
 * HumanPlayer.h
 *
 *  Created on: 22 Mar. 2019
 *      Author: dongmo
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

class HumanPlayer : public Player {
public:
	HumanPlayer(char ps):Player(ps) {}
	~HumanPlayer(){}

	void getMove(TicTacToe board, int& x, int& y) {
		do {
			cout << "Enter move: ";
			cin >> x >> y;
			cout << endl;
			x = x - 1;
			y = y - 1;
		} while (!board.isValidMove(x, y));
		return;
	}
};

#endif /* HUMANPLAYER_H_ */
