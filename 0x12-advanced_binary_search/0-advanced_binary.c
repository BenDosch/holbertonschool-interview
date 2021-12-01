#include "search_algos.h"

/**
* recurse_binary - Function that searches for a value in
* a sorted array of integers.
*
* @array: Pointer to the sorted array that is the subject of search
* @size: Size of the array
* @value: Value to find
* @offset: Offset of index from origional array.
*
* Return: Return: On sucess, return the index of the first match of value.
* On failure,  returns -1.
*/

int recurse_binary(int *array, size_t size, int value, size_t offset)
{
	size_t L = 0, M = 0, R = (size - 1), i;

	if (array != NULL)
	{
		printf("Searching in array: %d", array[L]);
		for (i = L + 1; i <= R; i++)
			printf(", %d", array[i]);
		printf("\n");
		M = ((L + R) / 2);
		if (array[L] == value && (size == 2 || L == R))
			return (L + offset);
		else if (L == R)
			return (-1);
		else if (array[M] == value)
			return (recurse_binary(array, (M + 1), value, offset));
		else if (array[M] < value)
			return (recurse_binary((array + (((int)M) + 1)),
					(size - (M + 1)), value, (offset + M + 1)));
		else if (array[M] > value)
			return (recurse_binary(array, (M + 1), value, offset));
	}
	return (-1);
}

/**
* advanced_binary - Function that searches for a value in
* a sorted array of integers.
*
* @array: Pointer to the sorted array that is the subject of search
* @size: Size of the array
* @value: Value to find
*
* Return: Return: On sucess, return the index of the first match of value.
* On failure,  returns -1.
*/

int advanced_binary(int *array, size_t size, int value)
{
	return (recurse_binary(array, size, value, 0));
}
