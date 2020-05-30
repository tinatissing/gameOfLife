#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Program Name: printGrid.c
 * Author(s): Tina Tissington
 * Purpose: Searching for a name in a specific decade.
 */ 

int dynNewGrid (int grid[100][100], int rows, int cols) {

	int x = 0;
	int y = 0;
	int live = 0;
	int oldGrid[100][100];

	for(y=0; y < rows; y++) {
		for(x=0; x < cols; x++) {
			oldGrid[y][x] = grid[y][x];
		}		
	}

	for (y = 0; y < rows; y++) {
		for (x = 0; x < cols; x++) {
			live = 0;
			if ((oldGrid[y-1][x-1] == 1) && (y > 0) && (x > 0)) {
				++live;
			}
			if ((oldGrid[y][x-1] == 1) && (x > 0)) {
				++live;
			}
			if ((oldGrid[y+1][x-1] == 1) && (x > 0) && (y < rows-1)) {
				++live;
			}
			if ((oldGrid[y-1][x] == 1) && (y > 0)) {
				++live;
			}
			if ((oldGrid[y+1][x] == 1) && (y < rows-1)) {
				++live;
			}
			if ((oldGrid[y-1][x+1] == 1) && (y > 0) && (x < cols-1)) {
				++live;
			}
			if ((oldGrid[y][x+1] == 1) && (x < cols-1)) {
				++live;
			}
			if ((oldGrid[y+1][x+1] == 1) && (x < cols-1) && (y < rows-1)) {
				++live;
			}

			if (oldGrid[y][x] == 1) {
				if ( (live < 2) || (live > 3) ) {
					grid[y][x] = 0;
				}
				else if (live == 2 || live == 3) {
					grid[y][x] = 1;
				}
			}
			else if (oldGrid[y][x] == 0) {
				if (live == 3) {
					grid[y][x] = 1;
				}
			}
		}
	}

	for(y=0; y < rows; y++) {
		for(x=0; x < cols; x++) {
			if (oldGrid[y][x] != grid[y][x]) {
				return(0);
			}
			else if ((y == rows-1) && (x == cols-1) && (oldGrid[y][x] == grid[y][x])) {
				return(-1);
			}
		}		
	}
	return(0);
}
