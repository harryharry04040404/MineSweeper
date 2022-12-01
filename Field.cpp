#include <cmath>
#include <ctime>
#include <stdio.h>
#include "Field.h"

int RandomValue(int min, int max)
{
	int result;
	result = min + rand() % (max - min + 1);
	return result;
}

void PrintField(Square field[NUM_ROWS][NUM_COLS]) {
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			
			printf(" % c", field[i][j].symbolToShow);
		}
		printf("\n");
	}
}

void FillField(Square field[NUM_ROWS][NUM_COLS], int minesPlanted)
{
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {

			field[i][j].Initialize();
		}
	}
	do {
		int x = RandomValue(0, 9);
		int y = RandomValue(0, 9);
		if (field[x][y].hasMine == false) {
			field[x][y].hasMine = true;
			minesPlanted++;
		}
	} while (minesPlanted < NUM_MINES);
	
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
}

void GameFinished(Square field[NUM_ROWS][NUM_COLS]) {

	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (field[i][j].hasMine == true) {
				for (int i = 0; i < NUM_ROWS; i++) {
					for (int j = 0; j < NUM_COLS; j++) {
						field[i][j].Reveal(i, j, field);
					}
				}
			}
		}
	}
		

}

void Play(int x, int y, Square field[NUM_ROWS][NUM_COLS]) {
	printf_s("input which square do you want to reveal");
	scanf_s("input x:%d input y:%d", field);
}

