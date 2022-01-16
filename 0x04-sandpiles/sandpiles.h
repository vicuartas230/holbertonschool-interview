#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int review_sandpile(int grid[3][3]);
void round_sandpile(int grid[3][3]);
static void print_grid(int grid[3][3]);
void reset_grid(int grid[3][3], int aux[3][3]);

#endif
