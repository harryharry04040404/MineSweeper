#include <cstdio>
#include <stdio.h>
#include <cmath>
#include <ctime>
#include "Field.h"



int main()
{
	//srand(time(NULL));
	Square field[NUM_ROWS][NUM_COLS];
	FillField(field, NUM_MINES);
	Play(field);
	PrintField(field);
	GameFinished(field);
}

