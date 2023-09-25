#ifndef GAME_H_
#define GAME_H_

class Game {
	TicTacToe board;
	Player* player[2];

public:
	Game(Player* p1, Player* p2) {
		player[0] = p1;
		player[1] = p2;
	}

	~Game() {
		delete player[0];
		delete player[1];
	}
	void play() {
		board.displayBoard();
		bool done = false;
		char playerSymbol = 'X';

		while (!done) {
			int x = -1;
			int y = -1;
			if (playerSymbol == 'X') {
				player[0]->getMove(board, x, y);
				board.addMove(playerSymbol, x, y);
				cout << "X makes a move (" << (x + 1) << "," << (y + 1) << ") "
						<< endl;
				board.displayBoard();
				done = checkWin(playerSymbol, board);
				playerSymbol = 'O';
			} else {
				player[1]->getMove(board, x, y);
				board.addMove(playerSymbol, x, y);
				cout << "O makes a move (" << (x + 1) << "," << (y + 1) << ") "
						<< endl;
				board.displayBoard();
				done = checkWin(playerSymbol, board);
				playerSymbol = 'X';
			}
		}
	}

	bool checkWin(char playerSymbol, TicTacToe board) {
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
