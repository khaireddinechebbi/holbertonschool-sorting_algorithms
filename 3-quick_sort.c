#include "sort.h"

/**
 * swap - Swaps specified array elements then prints array
 * @array: Array to swap elements
 * @size: Size of array
 * @i: First index to swap
 * @j: Second index to swap
 */
void swap(int *array, size_t size, int i, int j)
{
int tmp;

tmp = array[j];
if (array[i] != array[j])
{
array[j] = array[i];
array[i] = tmp;
print_array(array, size);
}
}

/**
 * lomuto_partition - array based on pivot
 * @array: Array to sort
 * @size: Size of array
 * @lo: Start index
 * @hi: End index
 *
 * Return: Position of lomuto_partition
 */
int lomuto_partition(int *array, size_t size, int lo, int hi)
{
int pivot, i, j;

pivot = array[hi];
i = lo - 1;
for (j = lo; j < hi; ++j)
if (array[j] < pivot)
{
++i;
swap(array, size, i, j);
}
++i;
swap(array, size, i, hi);
return (i);
}

/**
 * lomuto_sort - Recursion funtion
 * @array: Array to sway elements
 * @size: Size of array
 * @lo: Start index
 * @hi: End index
 */
void lomuto_sort(int *array, size_t size, int lo, int hi)
{
int p;

if  (lo < hi)
{
p = lomuto_partition(array, size, lo, hi);
lomuto_sort(array, size, lo, p - 1);
lomuto_sort(array, size, p + 1, hi);
}
}

/**
 * quick_sort - Quick sort algorithm
 * @array: Array to swap elements
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
if (array)
lomuto_sort(array, size, 0, size - 1);
}
