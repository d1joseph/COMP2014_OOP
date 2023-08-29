/*
 *
 *  Created on: 05/03/2019
 *      Author: dongmo
 */

#ifndef MINIMAXPLAYER_H_
#define MINIMAXPLAYER_H_

#include<iostream>
#include<sstream>
#include<limits>

using namespace std;

class MiniMaxPlayer: public Player {
private:
	int maxMove(TicTacToe& board);
	int minMove(TicTacToe& board);

	char opponent(int symbol) {
		return symbol == 'X' ? 'O' : 'X';
	}

	int steps;
public:
	MiniMaxPlayer(char ps) :
			Player(ps) {
		steps = 100000;
	}
	~MiniMaxPlayer() {
	}

	void getMove(TicTacToe board, int& x, int& y);
};

void MiniMaxPlayer::getMove(TicTacToe board, int& x, int& y) {

	vector<int> emptyCells = board.getEmptyPositions();
	if (emptyCells.empty())
		return;

	x = emptyCells[0] / 3;
	y = emptyCells[0] % 3;
	int max = -2;
	for (int index : emptyCells) {
		int i = index / 3;
		int j = index % 3;
		TicTacToe tempBoard(board);
		tempBoard.addMove(playerSymbol, i, j);
		char result = tempBoard.gameStatus();

		if (result == playerSymbol || result == 'D') {
			x = i;
			y = j;
			return;
		} else if (result == opponent(playerSymbol)) {
			continue;
		}

		int utility = minMove(tempBoard);
		if (utility > max) {
			x = i;
			y = j;
			max = utility;
		}
	}

	cout << "Minimax Utility = " << max << endl;

	return;
}

int MiniMaxPlayer::maxMove(TicTacToe& board) {
//	if (steps <= 0) return 0.01;
	vector<int> emptyCells = board.getEmptyPositions();
	if (emptyCells.empty())
		return -100;

	int maxUtility = -2;

	for (int index : emptyCells) {
		int i = index / 3;
		int j = index % 3;
		TicTacToe tempBoard(board);
		tempBoard.addMove(playerSymbol, i, j);
		if (tempBoard.gameStatus() == playerSymbol)
			return 1;
		if (tempBoard.gameStatus() == 'D')
			return 0;

		int utility = minMove(tempBoard);

		if (utility > maxUtility) {
			maxUtility = utility;
		}
	}

	steps--;
	return maxUtility;
}

int MiniMaxPlayer::minMove(TicTacToe& board) {
//	if (steps <= 0) return 0.01;
	vector<int> emptyCells = board.getEmptyPositions();
	if (emptyCells.empty())
		return -100;

	int minUtility = 2;
	for (int index : emptyCells) {
		int i = index / 3;
		int j = index % 3;
		TicTacToe tempBoard(board);
		tempBoard.addMove(opponent(playerSymbol), i, j);
		if (tempBoard.gameStatus() == opponent(playerSymbol))
			return -1;
		if (tempBoard.gameStatus() == 'D')
			return 0;

		int utility = maxMove(tempBoard);
		if (utility < minUtility) {
			minUtility = utility;
		}
	}

	steps--;
	return minUtility;
}

#endif /* MINIMAXPLAYER_H_ */
