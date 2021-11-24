#include "sort.h"

/**
 * heapify - makes an array into a heap
 *
 * @array: array to turn into a heap
 * @size: size of array passed
 * @root: parent node to swap with leaves if lesser
 * @n: total size of array to print
 */

void heapify(int *array, size_t size, size_t root, size_t n)
{
	int temp;
	size_t largest=root;
	size_t left = (2 * root) + 1;
	size_t right = (2 * root) + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;

		print_array(array, n);

		heapify(array, size, largest, n);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using the
 * sift-down Heap sort algorithm.
 *
 * @array: array to sort
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = (size - 1); i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		if (i != 0)
			print_array(array, size);

		heapify(array, i, 0, size);
	}
}
