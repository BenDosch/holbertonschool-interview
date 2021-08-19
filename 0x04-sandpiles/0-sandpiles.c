#include "sandpiles.h"

/**
 * sandpiles_sum - that computes the sum of two 3X3 sandpiles.
 * @grid1: Sandpile that is added to.
 * @grid2: Sandpile to add.
 * Return: None
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int temp[3][3], row, col;

    /* Innitial addition */
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            grid1[row][col] += grid2[row][col];
        }
    }
    while (unstable(grid1)){
        printf("=\n%d %d %d\n%d %d %d\n%d %d %d\n",
               grid1[0][0], grid1[0][1], grid1[0][2],
               grid1[1][0], grid1[1][1], grid1[1][2],
               grid1[2][0], grid1[2][1], grid1[2][2]);

        memset(&temp, 0, sizeof(temp));
        for (row = 0; row < 3; row++){
            for (col = 0; col < 3; col++){
                if (grid1[row][col] >= 4){
                    temp[row][col] += grid1[row][col] - 4;
                    if (row - 1 >= 0)
                        temp[row - 1][col] += 1;
                    if (row + 1 <= 2)
                        temp[row + 1][col] += 1;
                    if (col - 1 >= 0)
                        temp[row][col - 1] += 1;
                    if (col + 1 <= 2)
                        temp[row][col + 1] += 1;
                }
                else
                    temp[row][col] += grid1[row][col];
            }
        }
        sandpile_copy(grid1, temp);
    }
}

/**
 * unstable - checks if a sandpile is unstable
 * @grid: sandpile to check
 * Return: 0 if stable, 1 if unstable
 */

int unstable(int grid[3][3])
{
    int unstable = 0, i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] >= 4)
                unstable = 1;
        }
    }
    return unstable;
}

/**
 * sandplie_copy - coplies the value of grid2 into grid1
 * @grid1: grid to be reassigned
 * @grid2: grid to assign.
 * Return: void
 */

void sandpile_copy(int dest[3][3], int src[3][3]) {

   int row, col;
   
   for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            dest[row][col] = src[row][col];
        }
    }
}