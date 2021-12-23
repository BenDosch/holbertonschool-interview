#include "holberton.h"

/**
* main - Main function for infinate multiplication.
* @argc: Number of arguments passed to program.
* @argv: List of arguments passed to program.
*
* Returns: 1 on sucess.
*/

int main(int argc, char *argv[])
{
	unsigned long len1, len2, i = 0, j = 0;
	char *num1, *num2;

	if (argc != 3)
	{
		print_str("Error");
		exit(98);
	}

	len1 = get_len(argv[1]);
	len2 = get_len(argv[2]);

	if (len1 == 0 || len2 == 0)
	{
		print_str("0");
		return;
	}

	while (argv[1][i] == '0')
		i++;

	while (argv[2][j] == '0')
		j++;

	num1 = argv[1] + i;
	num2 = argv[2] + j;

	inf_mul(num1, len1, num2, len2);
	return (1);
}

/**
* print_str - Prints a string.
* @str: Pointer to first character of string to print.
*
* Returns: void
*/

void print_str(char *str)
{
	unsigned long i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/**
* get_len - gets the length of a valid number from a string.
*
* @str: pointer to first charcter of a string.
*
* Returns: Length of valid string.
*/

unsigned long get_len(char *str)
{
	unsigned long i = 0, len = 0;

	while(str[i] == '0')
		i++;

	if (str[i] == '\0' && i != 0)
		return (0);

	if (str[i] =='\0' && i == 0)
	{
		print_str("Error");
		exit(98);
	}

	while(str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		i++, len++;

	if (str[i] == '\0')
		return len;

	print_str("Error");
	exit(98);
}

/**
 * inf_mul - Preforms multiplication on infinately large numbers passed as
 * strings, then prints the result.
 *
 * @num1: Frist number to multiply
 * @len1: Length of first number.
 * @num2: Second number to multiply
 * @len2: Length of second number.
 *
 * Returns: void.
 */

void inf_mul(char *num1, unsigned long len1, char *num2, unsigned long len2)
{
	char product[len1 + len2 + 1];
	int digit_1, digit_2, carry;
	unsigned long i, j, k;

	for (i = 0; i < len1 + len2; i++)
		product[i] = '0' - 48;

	product[len1 + len2] = '\0';

	for (i = 0,  carry = 0; i < len1 ;i++)
	{
		digit_1 = num1[len1 - i - 1] - 48;

		for (j = 0; j < len2; j++)
		{
			digit_2 = num2[len2 - j - 1] - 48;
			product[len1 + len2 - i - j - 1] += (digit_1 * digit_2) % 10;
			carry = ((digit_1 * digit_2) / 10) + (product[len1 + len2 - i - j - 1] / 10);
			product[len1 + len2 - i - j - 1] %= 10;
			for (k = 2; carry > 0; k++)
			{
				product[len1 + len2 - i - j - k] += carry;
				carry = product[len1 + len2 - i - j - k] / 10;
				product[len1 + len2 - i - j - k] %= 10;
			}
		}
	}

	for (i = 0; i < len1 + len2; i++)
			product[i] += 48;

	for (i = 0; product[i] == '0'; i++)
		continue;

	for (;product[i] != '\0'; i++)
		_putchar(product[i]);
}
