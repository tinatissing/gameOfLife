#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Program Name: cgol.c
	Author: Tina Tissington
	Last Update: Nov. 6, 2019
	Function:
	Compilation: gcc -ansi -o cgol cgol.c
	Execution: ./cgol textFile.seed ticks rows columns
*/

void dynPrintGrid(int grid[100][100], int ticks, int rows, int cols);
int dynNewGrid(int grid[100][100], int rows, int cols);

int main ( int argc, char *argv[] ) {

	FILE *f1;
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	char string[100*100];
	int grid[100][100];
	int ticks = 0;
	int finalTick = 0;
	char input[20];
	int rows;
	int cols;
	int c = 0;

	if ( argc < 5 ) {
		printf ( "Usage: ./cgol fileName.seed numOfTicks rows columns\n" );
		exit ( 1 );
	} 
	else {
		finalTick = atoi(argv[2]);
		rows = atoi(argv[3]);
		cols = atoi(argv[4]);	
	}		

	if ( (f1 = fopen(argv[1], "r")) != NULL ) {
		while ( fgets(string, 100000, f1) != NULL ) {
			string[strlen(string)-1] = '\0';
			for (i = 0; i < strlen(string); i++) {

				if (string[i] == '0') {
					grid[y][x] = 0;
					x++;
					c++;
				}
				else if (string[i] == '1') {
					grid[y][x] = 1;
					x++;
					c++;
				}
			}
			x = 0;
			y++;
   		}
	}
	else {
   		printf ( "Cannot open file.\n" );
   	   	return ( 1 );
   	}

	if (c != rows*cols) {
		printf("Error: dimensions of the file are invalid\n");
		exit (0);
	}

	printf(" ");	
	for (i = 0; i < cols; i++) {
		printf("-");
	}
	printf("\n");
	
	for(i=0; i < rows; i++) {
		for(j=0; j < cols; j++) {
			if (j == 0) {
				printf("|");
			}
			if (grid[i][j] == 1) {
				printf("X");
			}
			if (grid[i][j] == 0) {
				printf(" ");			
			}
			if (j == cols-1) {
				printf("|");
			}
		}
		printf("\n");		
	}

		printf(" ");	
	for (i = 0; i < cols; i++) {
		printf("-");
	}
	printf("%d\n", ticks);

	printf("Start?(y or n)\n");
	fgets(input, 20, stdin);
	input[strlen(input)-1] = '\0';
		
	if (strcmp(input, "y") == 0) {
		dynNewGrid(grid, rows, cols);
	}
	else {
		return(-1);
	}

	while (ticks <= finalTick+1) {
		if (ticks == finalTick+1) {
			printf("Do you want to continue?(y or n)\n");
			fgets(input, 20, stdin);
			input[strlen(input)-1] = '\0';
			if (strcmp(input, "y") == 0) {
				finalTick = finalTick*2;
			}
			else {
				return(-1);
			}
		}

		dynNewGrid(grid, rows, cols);
		dynPrintGrid(grid, ticks, rows, cols);
		ticks++;
	}

	return (0);
}

void dynPrintGrid(int grid[100][100], int ticks, int rows, int cols) {
	int i=0, j=0;

	system("clear");

	printf(" ");	
	for (i = 0; i < cols; i++) {
		printf("-");
	}
	printf("\n");
	
	for(i=0; i < rows; i++) {
		for(j=0; j < cols; j++) {
			if (j == 0) {
				printf("|");
			}
			if (grid[i][j] == 1) {
				printf("X");
			}
			if (grid[i][j] == 0) {
				printf(" ");			
			}
			if (j == cols-1) {
				printf("|");
			}
		}
		printf("\n");		
	}

		printf(" ");	
	for (i = 0; i < cols; i++) {
		printf("-");
	}
	printf("%d\n", ticks);

	system ("sleep 0.5");

}
