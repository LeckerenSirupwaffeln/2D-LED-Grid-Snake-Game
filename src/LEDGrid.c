#include <stdio.h>
#include <stdlib.h>

#include "GlobalDefines.h"
#include "LEDGrid.h"

void LEDGrid(int *ptrarrayLEDGrid) {
	FILE *GRIDTextOutput;
	GRIDTextOutput = fopen("GRIDoutput.txt", "w");
	system("cls"); //clear CMD screen every time this function is called;
	for (int y = 1; y < GRIDLENGTH - 1; y++) {
		for (int x = 1; x < GRIDLENGTH - 1; x++) {
			fprintf(GRIDTextOutput, "%c", ptrarrayLEDGrid[y * GRIDLENGTH + x]);
			printf("%c", ptrarrayLEDGrid[y * GRIDLENGTH + x]);
		}
		fputs("\n", GRIDTextOutput);
		printf("\n");
	}
	fputs("\n", GRIDTextOutput);
	printf("\n");
	fclose(GRIDTextOutput);
}
