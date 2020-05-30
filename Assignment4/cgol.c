#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 40

/*
	Program Name: cgol.c
	Author: Tina Tissington
	Last Update: Nov. 6, 2019
	Function:
	Compilation: gcc -ansi -o cgol cgol.c
	Execution: ./cgol
*/

/*TA made these global, so I hope it's okay!*/
void printGrid(int grid[ROWS][COLS], int ticks);
int newGrid(int grid[ROWS][COLS]);

int main ( int argc, char *argv[] ) {

	FILE *f1;
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	char string[ROWS*COLS];
	int grid[ROWS][COLS];
	int ticks = 0;
	int finalTick = 0;
	char input[20];
	int c = 0;

	if ( argc < 2 ) {
		printf ( "Usage: ./cgol fileName.seed numOfTicks\n" );
		exit ( 1 );
	} 
	else if ( argc == 3 ) {
		finalTick = atoi(argv[2]);
   	}

	if (finalTick == 0) {
		finalTick = 50;
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
   	   	return ( -2 );
   	}

	if (c != ROWS*COLS) {
		printf("Error: dimensions of file are invalid\n");
		exit(0);
	}

	printf(" ");	
	for (i = 0; i < COLS; i++) {
		printf("-");
	}
	printf("\n");
	
	for(i=0; i < ROWS; i++) {
		for(j=0; j < COLS; j++) {
			if (j == 0) {
				printf("|");
			}
			if (grid[i][j] == 1) {
				printf("X");
			}
			if (grid[i][j] == 0) {
				printf(" ");			
			}
			if (j == COLS-1) {
				printf("|");
			}
		}
		printf("\n");		
	}

		printf(" ");	
	for (i = 0; i < COLS; i++) {
		printf("-");
	}
	printf("%d\n", ticks);

	printf("Start?(y or n)\n");
	fgets(input, 20, stdin);
	input[strlen(input)-1] = '\0';
		
	if (strcmp(input, "y") == 0) {
		newGrid(grid);
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

		newGrid(grid);
		printGrid(grid, ticks);
		ticks++;
	}

	return (0);
}

void printGrid(int grid[ROWS][COLS], int ticks) {
	int i=0, j=0;

	system("clear");

	printf(" ");	
	for (i = 0; i < COLS; i++) {
		printf("-");
	}
	printf("\n");
	
	for(i=0; i < ROWS; i++) {
		for(j=0; j < COLS; j++) {
			if (j == 0) {
				printf("|");
			}
			if (grid[i][j] == 1) {
				printf("X");
			}
			if (grid[i][j] == 0) {
				printf(" ");			
			}
			if (j == COLS-1) {
				printf("|");
			}
		}
		printf("\n");		
	}

		printf(" ");	
	for (i = 0; i < COLS; i++) {
		printf("-");
	}
	printf("%d\n", ticks);

	system ("sleep 0.5");

}


