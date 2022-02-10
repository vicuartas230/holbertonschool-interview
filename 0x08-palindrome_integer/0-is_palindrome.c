#include "palindrome.h"

/**
 * is_palindrome - This function checks whether or not a
 * given unsigned integer is a palindrome.
 * @n: The number to be checked.
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
	int i = 0, right = 0, left = 0, mid = 0;
	unsigned long j = 1, number = n;

	while (number > 0)
	{
		i++;
		number /= 10, j *= 10;
	}
	j /= 10;
	mid = i / 2;
	while (i > mid)
	{
		right = n / j;
		left = n % 10;
		if (right != left)
		return (0);
		i--;
		n %= j;
		n /= 10;
		j /= 100;
	}
	return (1);
}
