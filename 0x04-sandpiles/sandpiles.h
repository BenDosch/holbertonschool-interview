#ifndef SANDPILES_H     
#define SANDPILES_H     

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int unstable(int grid[3][3]);
void sandpile_copy(int grid1[3][3], int grid2[3][3]);

#endif