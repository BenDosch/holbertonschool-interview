#include "holberton.h"

/**
 * shift_1 - shifts s1 until = to s2
 * 
 * @s1: string 1
 * @s2: string 2
 * 
 * Return: address of shifted s1
 */

char * shift_1(char *s1, char *s2)
{
	if (*s1 != *s2 && *s1 != '\0')
		return (shift_1(s1 + 1, s2));
	return (s1);
}

/**
 * shift_2 - shifts 2 past *
 * 
 * @s2: string to shift
 * 
 * Return: shifted addresss of s2
 */

char * shift_2(char *s2)
{
	if (*s2 == '*')
		return (shift_2((s2 + 1)));

	return (s2);
}

/**
 * wild_count - counts how many characters since the last wildcard
 *
 * @s2: the second string to backtrack.
 * @count: the count of characters since the last wildcard
 *
 * Return: the count of characters since the last wildcard
 */

size_t wild_count(char *s2, size_t count)
{
	if (*s2 != '*')
	{
		return (wild_count(s2 - 1, count++));
	}
	return (count);
}

/**
 * test - tests if s1 = s2
 * 
 * @s1: string 1
 * @s2: string 2
 * @wild: existance of wildcard found in string 2
 * 
 * Retrun: 1 if same, 0 false
 */

int test(char *s1, char *s2, int wild)
{
    size_t wilds;
    
    if (s1 && s2 == NULL)
		return (1);
	if (s1 == NULL)
		return (0);
	if (s2 == NULL)
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
	{
	    wild = 1;
		s2 = shift_2(s2);
		s1 = shift_1(s1, s2);
		return (test((s1 + 1), (s2 + 1), wild));
	}
	else if (*s1 != *s2 && wild)
	{
		wilds = wild_count(s2, 0);
		s2 -= wilds;
		s1 -= wilds;
		if (*s1 == '\0' || *s1 + 1 == '\0')
			return (0);
		s1 += 2;
		return (test((s1 + 1), (s2 + 1), wild));
	}
	else if (*s1 != *s2)
	    return (0);

	return (test((s1 + 1), (s2 + 1), wild));
	
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
	return (test(s1, s2, 0));
}
