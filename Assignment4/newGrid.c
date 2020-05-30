#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 40

/* 
 * Program Name: printGrid.c
 * Author(s): Tina Tissington
 * Purpose: Searching for a name in a specific decade.
 */ 

int newGrid (int grid[ROWS][COLS]) {

	int x = 0;
	int y = 0;
	int live = 0;
	int oldGrid[ROWS][COLS];

	for(y=0; y < ROWS; y++) {
		for(x=0; x < COLS; x++) {
			oldGrid[y][x] = grid[y][x];
		}		
	}

	for (y = 0; y < ROWS; y++) {
		for (x = 0; x < COLS; x++) {
			live = 0;
			if ((oldGrid[y-1][x-1] == 1) && (y > 0) && (x > 0)) {	
				++live;
			}
			if ((oldGrid[y][x-1] == 1) && (x > 0)) {
				++live;
			}
			if ((oldGrid[y+1][x-1] == 1) && (x > 0) && (y < ROWS-1)) {
				++live;
			}
			if ((oldGrid[y-1][x] == 1) && (y > 0)) {
				++live;
			}
			if ((oldGrid[y+1][x] == 1) && (y < ROWS-1)) {
				++live;
			}
			if ((oldGrid[y-1][x+1] == 1) && (y > 0) && (x < COLS-1)) {
				++live;
			}
			if ((oldGrid[y][x+1] == 1) && (x < COLS-1)) {
				++live;
			}
			if ((oldGrid[y+1][x+1] == 1) && (x < COLS-1) && (y < ROWS-1)) {
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

	for (y = 0; y < ROWS; y++) {
		for (x = 0; x < COLS; x++) {
			if (oldGrid[y][x] != grid[x][y]) {
				return(0);
			}
		}
	}
	
	exit(0);
}
