#include <cstdio>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Field.h"
#include "Square.h"

int RandomValue(int min, int max)
{
	int result;
	result = min + rand() % (max - min + 1);
	return result;
}

void FillField(Square field[NUM_ROWS][NUM_COLS]) {
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {

			field[i][j].Initialize();
		}
	}
}

void PlantMines(int minesPlanted, Square field[NUM_ROWS][NUM_COLS]) {
	do {
		int x = RandomValue(0, 9);
		int y = RandomValue(0, 9);
		if (field[x][y].hasMine == false) {

			field[x][y].hasMine = true;
			minesPlanted++;
		}
	} while (minesPlanted < NUM_MINES);
}


int main()
{
	srand(time(NULL));
	Square field[NUM_ROWS][NUM_COLS];

	FillField(field);
	PlantMines(0, field);
	
	
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			field[i][j].CalculateNearbyMines(i, j, field);
		}
	}

	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			field[i][j].Reveal(i, j, field);
		}
	}

	PrintField(field);

}

