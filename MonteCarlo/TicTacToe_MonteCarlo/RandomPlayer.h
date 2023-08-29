/*
 * RandomPlayer.h
 *
 *  Created on: 22 Mar. 2019
 *      Author: dongmo
 */

#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

class RandomPlayer {
public:
	void getMove(Board board, int& x, int& y) {
		board.getaRandomMove(x,y);
		return;
	}
};

#endif /* RANDOMPLAYER_H_ */
