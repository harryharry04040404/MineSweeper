#include "Square.h"

void Square::Initialize() {

	hasMine = false;
	symbolToShow = '?';
	nearbyMines = 0;
}

void Square::CalculateNearbyMines(int x, int y, Square field[NUM_ROWS][NUM_COLS]) {

	if (field[x][y].hasMine == true) {
		if ((x > 0) && (y > 0) && (x < 9) && (y < 9)) {
			field[x][y + 1].nearbyMines += 1;
			field[x][y - 1].nearbyMines += 1;
			field[x + 1][y].nearbyMines += 1;
			field[x - 1][y].nearbyMines += 1;
			field[x + 1][y + 1].nearbyMines += 1;
			field[x - 1][y - 1].nearbyMines += 1;
			field[x + 1][y - 1].nearbyMines += 1;
			field[x - 1][y + 1].nearbyMines += 1;
		}
		else if ((x == 0) && (y == 0)) {
			field[x][y + 1].nearbyMines += 1;
			field[x + 1][y].nearbyMines += 1;
			field[x + 1][y + 1].nearbyMines += 1;
		}
		else if ((x == 0) && (y == 9)) {
			field[x][y - 1].nearbyMines += 1;
			field[x + 1][y].nearbyMines += 1;
			field[x + 1][y - 1].nearbyMines += 1;
		}
		else if ((x == 0) && (y < 9) && (y > 0)) {
			field[x][y + 1].nearbyMines += 1;
			field[x][y - 1].nearbyMines += 1;
			field[x + 1][y].nearbyMines += 1;
			field[x + 1][y + 1].nearbyMines += 1;
			field[x + 1][y - 1].nearbyMines += 1;
		}
		else if ((x == 9) && (y == 0)) {
			field[x][y + 1].nearbyMines += 1;
			field[x - 1][y].nearbyMines += 1;
			field[x - 1][y + 1].nearbyMines += 1;
		}
		else if ((x == 9) && (y == 9)) {
			field[x][y - 1].nearbyMines += 1;
			field[x - 1][y].nearbyMines += 1;
			field[x - 1][y - 1].nearbyMines += 1;
		}
		else if ((x == 9) && (y < 9) && (y > 0)) {
			field[x][y + 1].nearbyMines += 1;
			field[x][y - 1].nearbyMines += 1;
			field[x - 1][y].nearbyMines += 1;
			field[x - 1][y + 1].nearbyMines += 1;
			field[x - 1][y - 1].nearbyMines += 1;
		}
	}
}

void Square::Reveal(int x, int y, Square field[NUM_ROWS][NUM_COLS]) {
	if (hasMine) {
		symbolToShow = 'X';
	}
	else {
		symbolToShow = '0' + nearbyMines;
	}
}