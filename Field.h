#include <stdio.h>
#include "Square.h"

void FillField(Square field[NUM_ROWS][NUM_COLS], int minesPlanted);
void PrintField(Square field[NUM_ROWS][NUM_COLS]);
void Play(Square field[NUM_ROWS][NUM_COLS]);
void GameFinished(Square field[NUM_ROWS][NUM_COLS]);