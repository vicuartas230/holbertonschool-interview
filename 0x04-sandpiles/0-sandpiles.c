#include "sandpiles.h"

/**
 * sandpiles_sum - This function computes the sum of two sandpiles.
 * @grid1: First array of numbers.
 * @grid2: Second array of numbers.
 * Return: Nothing.
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;

	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			j++;
		}
		i++;
	}
    print_grid(grid1);
    printf("\n");
	round_sandpile(grid1);
}

/**
 * review_sandpile - This function reviews if a grid is stable.
 * @grid: The matrix of numbers.
 * Return: 0 if grid is stable and 1 if not. 
 */

int review_sandpile(int grid[3][3])
{
	int i = 0, j = 0;

	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (grid[i][j] > 3)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * round_sandpile - This function stabilizes a grid.
 * @grid: The matrix of numbers.
 * Return: Nothing.
 */

void round_sandpile(int grid[3][3])
{
	int i = 0, j = 0,
    total[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

	if (review_sandpile(grid))
	{
        while (i < 3)
		{
			j = 0;
			while (j < 3)
			{
				if (grid[i][j] < 4)
					total[i][j] = grid[i][j];
				j++;
			}
			i++;
		}
        i = 0;
		while (i < 3)
		{
			j = 0;
			while (j < 3)
			{
				if (grid[i][j] >= 4)
				{
					total[i][j] = grid[i][j] - 4;
					(total[i - 1][j])++;
					total[i][j + 1]++;
					total[i + 1][j]++;
					(total[i][j - 1])++;
				}
                j++;
			}
			i++;
		}
        printf("grid:\n");
		print_grid(grid);
        printf("\n");
        grid = total;
        printf("total:\n");
        print_grid(total);
		printf("\n");
		round_sandpile(grid);
	}
}

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
