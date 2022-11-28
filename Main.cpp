#include <cstdio>
#include <stdio.h>
#include <cmath>
#include <ctime>
#include "Field.h"
#include "Square.h"




int main()
{
	srand(time(NULL));
	Square field[NUM_ROWS][NUM_COLS];
	FillField(field, 0);
	PrintField(field);
}

