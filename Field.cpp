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

bool AskInputCoordinates(char coordChar, int& coord) {
	printf_s("Enter %c: ", coordChar);
	scanf_s("%d", &coord);
	bool bottomFloor = coord >= 0;
	bool topFloor = coord <= 9;
	return (bottomFloor && topFloor);
}

void RecursiveReveal(int x, int y, Square field[NUM_ROWS][NUM_COLS], int& positionsRevealed) {
	field[y][x].Reveal(x, y, field);
	positionsRevealed++;

	if (field[y][x].nearbyMines != 0 || field[y][x].hasMine) {
		return;
	}

	if (x > 0) {

	}
}

void Play(Square field[NUM_ROWS][NUM_COLS]) {
	bool playing = true;
	int inputX, inputY;
	int positionsRevealed = 0;
	
	while (playing) {
		PrintField(field);

		printf_s("Enter the position that you want to check\n");
		if (!AskInputCoordinates('X', inputX)) {
			printf_s("Invalid X coordinate\n");
			system("pause");
			system("cls");
			continue;
		}
		if (!AskInputCoordinates('Y', inputY)) {
			printf_s("Invalid Y coordinate\n");
			system("pause");
			system("cls");
			continue;
		}
		if (field[inputY][inputX].symbolToShow != '?') {
			printf_s("Position already revealed\n");
			system("pause");
			system("cls");
			continue;
		}
		RecursiveReveal(inputX, inputY, field, positionsRevealed);
		if (field[inputY][inputX].hasMine) {
			printf_s("There is a mine at (%d, %d)!!! You lost :(\n", inputX, inputY);
			playing = false;
		}
		else {
			printf_s("The position (%d, %d) is clear!!!\n", inputX, inputY);
			if (positionsRevealed == 89) {
				printf_s("\n\nYou won!!! There are no more mines. You avoided Radev... For now >:^)\n");
				playing = false;
			}
		}
		system("pause");
		system("cls");
	}
}

