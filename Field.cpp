#include "Field.h"

void PrintField(Square field[NUM_ROWS][NUM_COLS]) {
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			
			printf(" % c", field[i][j].symbolToShow);
		}
		printf("\n");
	}
}