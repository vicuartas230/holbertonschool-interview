#include "sandpiles.h"

/**
 * sandpiles_sum - This function computes the sum of two sandpiles.
 * @grid1: First array of numbers.
 * @grid2: Second array of numbers.
 * Return: Nothing.
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i = 0, j = 0, total[3][3];

    while (i < 3)
    {
        while (j < 3)
        {
            total[i][j] = grid1[i][j] + grid2[i][j];
            j++;
        }
        i++;
    }
}

int review_sandpile(int grid[3][3])
{
    int i = 0, j = 0;

    while (i < 3)
    {
        while (j < 3)
        {
            if (grid[i][j] > 3)
            {
                return (0);
            }
            
            j++;
        }
        i++;
    }
    return (1);
}
