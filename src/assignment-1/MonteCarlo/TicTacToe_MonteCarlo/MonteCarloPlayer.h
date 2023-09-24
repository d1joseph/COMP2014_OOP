/*
 * MonteCarloPlayer.h
 *
 *  Created on: 22 Mar. 2019
 *      Author: dongmo
 */

#ifndef MONTECARLOPLAYER_H_
#define MONTECARLOPLAYER_H_

const int simulation_times = 100;

class MonteCarloPlayer {
	char playerSymbol;
public:
	MonteCarloPlayer(char ps) {
		playerSymbol = ps;
	}

	void getMove(Board board, int& x, int& y) {

		vector<int> emptyCells = board.getEmptyPositions();
		if (emptyCells.empty())
			return;

		priority_queue<Cell> moves;

		for (int index : emptyCells) {
			int i = index / 3;
			int j = index % 3;
			Board tempBoard(board);
			tempBoard.addMove(i, j);
			if (tempBoard.isFull()) {
				if (tempBoard.gameStatus() == playerSymbol) {
					x = i;
					y = j;
					return;
				} else {
					continue;
				}
			}

			double utility = simulation(tempBoard);

			Cell c(i, j, utility);
			moves.push(c);
		}

		if (moves.size() > 0) {
			x = moves.top().x;
			y = moves.top().y;

			cout << moves.size() << " Monte Carlo Utility = " << moves.top().heuristic << " at ("
					<< x << "," << y << ")" << endl;
		}

		return;
	}

	double simulation(Board board) {

		int winning = 0;

		for (int i = 0; i < simulation_times; i++) {
			Board tempBoard(board);
			winning += expansion(tempBoard);
		}

		return ((double) winning / (double) simulation_times);
	}

	int expansion(Board board) {
        char gameStatus = board.gameStatus();
		if (gameStatus != 'C') {
			if ( gameStatus == playerSymbol)
				return  1; //score 1 if wins
			else if (gameStatus == 'D')
				return 0; //score 0 if tie
			else
				return -1; //score -1 if lose
		}

		int x, y;
		board.getaRandomMove(x, y);
		board.addMove(x, y);
		return expansion(board);
	}

};

#endif /* MONTECARLOPLAYER_H_ */
