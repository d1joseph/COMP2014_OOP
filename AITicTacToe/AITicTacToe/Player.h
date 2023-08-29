/*
 * Player.h
 *
 *  Created on: 16 Aug. 2020
 *      Author: dongmo
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
protected:
	char playerSymbol;
public:
	Player(char ps) {
		playerSymbol = ps;
	}
	virtual ~Player(){}

	virtual void getMove(TicTacToe board, int& x, int& y) = 0;
	char getPlayerSymbol() {
		return playerSymbol;
	}
};

#endif /* PLAYER_H_ */
