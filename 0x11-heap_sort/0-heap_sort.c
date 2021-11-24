#include "sort.h"

/**
 * downsift - the downsift method for heap ort
 * @a: the array being heapified
 * @n: starting index for array
 * @i: ending index for array
 * @size: size for printing references
 * Return: void no return
 */

void downsift(int *a, int n, int i, size_t size)
{
	int m = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int t;

	if (l < n && a[l] > a[m])
		m = l;
	if (r < n && a[r] > a[m])
		m = r;

	if (m != i)
	{
		t = a[i];
		a[i] = a[m];
		a[m] = t;
		print_array(a, size);
		downsift(a, n, m, size);
	}
}

/**
 * heap_sort - performs the heap sort on an array
 * @array: The array being heap sorted
 * @size: the size of the array
 * Return: void, no return
 */

void heap_sort(int *array, size_t size)
{
	int i, t, n = size;

	if (!array || size < 2)
		return;
	for (i = (n - 2) / 2; i >= 0; i--)
		downsift(array, n, i, size);
	for (i = (n - 1); i >= 0; i--)
	{
		t = array[0];
		array[0] = array[i];
		array[i] = t;
		if (i != 0)
			print_array(array, size);
		downsift(array, i, 0, size);
	}
}
