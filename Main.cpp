#include <cstdio>
#include <stdio.h>
#include <cmath>
#include <ctime>
#include "Field.h"





int main()
{
	srand(time(NULL));
	Square field[NUM_ROWS][NUM_COLS];
	Play(field);
	FillField(field, 0);
	PrintField(field);
	GameFinished(field);
}


