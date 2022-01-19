#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int left[], int right[], size_t size);
void CopyArray(int *dest, int start, int end, int *src);
void TopDownSplitMerge(int left[], int right[], size_t size);

#endif /*SORT_H*/
