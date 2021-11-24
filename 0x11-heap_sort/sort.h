#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t root, size_t n);
void print_array(const int *array, size_t size);

#endif
