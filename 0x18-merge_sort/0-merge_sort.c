#include "sort.h"


/**
 * merge_sort - sorts array of ints in ascending order using Merge Sort
 *              algorithm.
 *
 * @array: array
 * @size: size of array
 *
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (array && size > 1)
	{
		temp = malloc(sizeof(int) * size);
		CopyArray(array, 0, size, temp);
		TopDownSplitMerge(array, temp, size);
		free(temp);
	}
}
/**
 * TopDownSplitMerge - split merge
 *
 * @left: left side array array
 * @right: right side array
 * @size: size of combined array
 *
 * Return: void
 */

void TopDownSplitMerge(int left[], int right[], size_t size)
{
	int mid = 0;

	if (size < 2)
		return;

	mid = size / 2;

	TopDownSplitMerge(left, right, mid);
	TopDownSplitMerge(left + mid, right, size - mid);
	merge(left, right, size);
}
/**
 * merge - merges two subarrays
 *
 * @left: left side array array
 * @right: right side array
 * @size: size of combined array
 *
 * Return: void
 */

void merge(int left[], int right[], size_t size)
{
	size_t mid = size / 2;
	size_t i = 0, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(left + mid, size - mid);
	for (i = 0; k < size; k++)
	{
		if (i < mid && (j == size || left[i] <= left[j]))
		{
			right[k] = left[i];
			i++;
		}
		else
		{
			right[k] = left[j];
			j++;
		}
	}
	for (i = 0; i < size; i++)
		left[i] = right[i];

	printf("[Done]: ");
	print_array(right, size);
}
/**
 * CopyArray - makes a copy of an array
 *
 * @dest: destination to copy too
 * @start: starting index
 * @end: ending index
 * @src: source array
 *
 * Return: void
 */

void CopyArray(int *dest, int start, int end, int *src)
{
	int i;

	for (i = start; i < end; i++)
		src[i] = dest[i];
}
