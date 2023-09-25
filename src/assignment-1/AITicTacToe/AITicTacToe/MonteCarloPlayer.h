/*
 * MonteCarloPlayer.h
 *
 *  Created on: 22 Mar. 2019
 *      Author: dongmo
 */

#ifndef MONTECARLOPLAYER_H_
#define MONTECARLOPLAYER_H_

const int TIMES = 500;

class MonteCarloPlayer : public Player {
public:
	MonteCarloPlayer(char ps) : Player(ps) {}

	void getMove(TicTacToe board, int& x, int& y) {

		vector<int> emptyCells =board.getEmptyPositions();

		if (emptyCells.empty())
			return;

		double maxUtility = -1.0;

		for (int index : emptyCells) {
			int i = index / 3;
			int j = index % 3;
			TicTacToe tempBoard(board);
			tempBoard.addMove(playerSymbol, i, j);

			double utility = simulation(tempBoard);

			if (utility > maxUtility) {
				maxUtility = utility;
				x = i;
				y = j;
			}
		}

		cout << "Monte Carlo Utility = " << maxUtility  << endl;

		return;
	}

	double simulation(TicTacToe board) {
		double winning = 0.0;

		for (int i = 0; i < TIMES; i++) {
			TicTacToe tempBoard(board);
			winning += expansion((playerSymbol == 'X') ? 'O' : 'X', tempBoard);
		}

		return winning/TIMES;
	}



	double expansion(char player, TicTacToe board) {

		if (board.gameStatus() == playerSymbol) {
			return 1;
		} else if (board.gameStatus() == 'D') {
			return 0.5;
		} else if (board.gameStatus() != 'C') {
			return 0;
		}

		vector<int> emptyCells = board.getEmptyPositions();

		int index = emptyCells[rand() % emptyCells.size()];

		int x = index / 3;
		int y = index % 3;

		board.addMove(player, x, y);

		player = (player == 'X') ? 'O' : 'X';

		return expansion(player, board);
	}

};

#endif /* MONTECARLOPLAYER_H_ */
