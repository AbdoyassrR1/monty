#include "monty.h"

/**
 * is_integer - Checks if a given number is an integer
 * @n: The number to check
 *
 * Return: 1 if the number is an integer, 0 otherwise
 */
int is_int(int n)
{
	if (n == (int)n)
		return (1);
	else
		return (0);
}
