#include "holberton.h"
/**
 * test - tests if s1 = s2
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if same, 0 false
 */

int test(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
	    return (1);
	if (*s1 != *s2 && *s2 != '*')
		return (0);
	if (*s2 == '*' && *(s2 + 1) == '\0')
		return (1);
	if (*s2 == '*' && *(s2 + 1) == '*')
		return (test(s1, s2 + 1));
	if (*s1 == '\0' && *s2 == '*')
		return (test(s1, s2 + 1));
	if (*s1 == *s2)
		return (test(s1 + 1, s2 + 1));
	if (*s2 == '*' && *(s2 + 1) == *s1)
		return (test(s1 + 1, s2 + 1)
			|| test(s1 + 1, s2)
			|| test(s1, s2 + 1)
			);
	if (*s2 == '*' && *(s2 + 1) == *(s1 + 1))
		return (test(s1 + 1, s2 + 1));
	if (*s2 == '*' && *(s2 + 1) != *(s1 + 1))
		return (test(s1 + 1, s2));
	return (1);
}

/**
 * wildcmp - runs recursive test on s1 and s2 to see if they match
 *
 * @s1: sting to test
 * @s2: stirng potentialy with * to test
 *
 * Return: 1 if they match 0 if they don't
 */

int wildcmp(char *s1, char *s2)
{
	return (test(s1, s2));
}
