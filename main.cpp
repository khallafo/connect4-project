#include <iostream>
using namespace std;

int main()
{
	// WE Filled all array indexes with 0 just for view
	int game[8][8] = {
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 }
	};

	int player = 1;			// it's player 1 turn as default
	int x, y;				// Coordinates X AND Y
	bool winner = false;

	while (true) {

		bool Err = false;

		switch (player) {
			case 1:
				cout << "Player 1 turn\n";
				break;
			case 2:
				cout << "Player 2 turn\n";
				break;
		}

		cout << "Enter X and Y\n";
		cin >> x >> y;

		if (x > 7 || x < 0 || y > 7 || y < 0) {

			Err = true;
			cout << "try again, the Coordinates must be between 0 and 7\n";

		}
		else if (game[y][x] != 0) {

			Err = true;
			cout << "this cell is filled ,try another \n";

		}
		else if (y != 0 && game[y - 1][x] == 0) {

			Err = true;
			cout << "try again, the previous cell mustn't be empty \n";

		}

		if (Err) continue; // Give another chance to player

		game[y][x] = player;



		// START => CHECK CONNECT 4 HORIZONTALLY

		int isPassed4 = 0;

		for (int hor = 0; hor < 8; hor++) {
			if (game[y][hor] == player) {
				isPassed4++;
				if (isPassed4 == 4) break;
			}
			else
				isPassed4 = 0;
		}

		if (isPassed4 == 4) {
			winner = true;
			break;
		}

		// END => CHECK CONNECT 4 HORIZONTALLY

		// START => CHECK CONNECT 4 VERTICALLY

		isPassed4 = 0;

		for (int ver = 0; ver < 8; ver++) {
			if (game[ver][x] == player) {
				isPassed4++;
				if (isPassed4 == 4) break;
			}
			else
				isPassed4 = 0;
		}

		if (isPassed4 == 4) {
			winner = true;
			break;
		}

		// END => CHECK CONNECT 4 VERTICALLY

		// START => CHECK CONNECT 4 DIAGONALLY 1

		int small = x;
		if (x > y)	small = y;

		isPassed4 = 0;

		for (int dia1 = 0; dia1 < 8; dia1++) {
			if (game[y - small + dia1][x - small + dia1] == player) {
				isPassed4++;
				if (isPassed4 == 4) break;
			}
			else
				isPassed4 = 0;
		}

		if (isPassed4 == 4) {
			winner = true;
			break;
		}

		// END => CHECK CONNECT 4 DIAGONALLY 1

		// START => CHECK CONNECT 4 DIAGONALLY 2

		int maxim = 7;
		if (x + y < 7) maxim = x + y;

		int small2 = y;
		if (7 - x < y)	small = 7 - x;

		isPassed4 = 0;

		for (int dia2 = 0; dia2 < 8; dia2++) {
			if (game[y - small2 + dia2][maxim - dia2] == player) {
				isPassed4++;
				if (isPassed4 == 4) break;
			}
			else
				isPassed4 = 0;
		}

		if (isPassed4 == 4) {
			winner = true;
			break;
		}

		// END => CHECK CONNECT 4 DIAGONALLY 2

		// Game is over if the last row filled without connect 4
		int gameOver = false;
		for (int i = 0; i < 8; i++)
			if (game[7][i] == 0) {
				gameOver = false;
				break;
			}
			else
				gameOver = true;
		if (gameOver) break;

		switch (player) {
			case 1:
				player = 2;
				break;
			case 2:
				player = 1;
				break;
		}

		for (int frame = 0; frame < 10; frame++) cout << "* "; cout << endl;
		for (int i = 7; i >= 0; i--) {
			cout << "* ";
			for (int j = 0; j < 8; j++) cout << game[i][j] << " ";
			cout << "*\n";
		}
		for (int frame = 0; frame < 10; frame++) cout << "* "; cout << endl;

	}

	if (winner)
		cout << "The winner is player " << player << endl;
	else
		cout << "Game over, nobody has won" << endl;

	return 0;
}
