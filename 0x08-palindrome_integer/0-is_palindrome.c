#include "palindrome.h"

/**
 * is_palindrome: Function that checks whether or not a given unsigned integer
 *                is a palindrome.
 * @n: The number to be checked.
 *
 * Returns: 1 if N is a palindrome, else 0.
 */

int is_palindrome(unsigned long n)
{
	unsigned long num = n, new = 0, diget;

	while (num / 10 > 0)
	{
		diget = num % 10;
		new = (10 * new) + diget;
		num /= 10;
	}
	new = (10 * new) + num;

	if (new == n)
		return (1);

	return (0);
}
