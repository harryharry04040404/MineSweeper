#pragma once
#define NUM_ROWS 10
#define NUM_COLS 10
#define NUM_MINES 10

struct Square {

	bool hasMine;
	char symbolToShow;
	int nearbyMines;

	void Initialize();
	void Reveal(int x, int y, Square field[NUM_ROWS][NUM_COLS]);
	void CalculateNearbyMines(int x, int y, Square field[NUM_ROWS][NUM_COLS]);
};