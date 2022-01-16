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
	printf("\n");
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
	aux[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	while (review_sandpile(grid))
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid[i][j] < 4)
					aux[i][j] = grid[i][j];
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid[i][j] >= 4)
				{
					aux[i][j] += grid[i][j] - 4;
					aux[i + 1][j]++;
					aux[i - 1][j]++;
					aux[i][j + 1]++;
					aux[i][j - 1]++;
				}
			}
		}
		reset_grid(grid, aux);
		print_grid(grid);
	}
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */

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

/**
 * reset_grid - This function initializes a grid.
 * @grid: The array to set to 0.
 * Return: Nothing.
 */

void reset_grid(int grid[3][3], int aux[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] = aux[i][j];
			aux[i][j] = 0;
		}
	}
}
