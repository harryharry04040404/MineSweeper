#pragma once
#include <stdio.h>
#include "Square.h"
#define NUM_ROWS 10
#define NUM_COLS 10
#define NUM_MINES 10

void FillField(Square field[NUM_ROWS][NUM_COLS]);
void PrintField(Square field[NUM_ROWS][NUM_COLS]);
void Play(Square field[NUM_ROWS][NUM_COLS]);
void GameFinished(Square field[NUM_ROWS][NUM_COLS]);