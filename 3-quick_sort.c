#include "sort.h"
/**
* swap - Swap two integers in an array.
* @a: The first integer to swap.
* @b: The second integer to swap.
*/
void swap(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* lomuto_partition - Order a subset of an array of integers according to
*                    the lomuto partition scheme (last element as pivot).
* @array: The array of integers.
* @size: The size of the array.
* @low: The starting index of the subset to order.
* @high: The ending index of the subset to order.
* Return: The final partition index.
*/
int lomuto_partition(int *array, size_t size, int low, int high)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
swap(&array[i], &array[j]);
print_array(array, size);
}
}
swap(&array[i + 1], &array[high]);
print_array(array, size);
return (i + 1);
}

/**
* lomuto_sort - Implement the quicksort algorithm through recursion.
* @array: An array of integers to sort.
* @size: The size of the array.
* @low: The starting index of the array partition to order.
* @high: The ending index of the array partition to order.
*/
void lomuto_sort(int *array, size_t size, int low, int high)
{
int p;
if (low < high)
{
p = lomuto_partition(array, size, low, high);
lomuto_sort(array, size, low, p - 1);
lomuto_sort(array, size, p + 1, high);
}
}

/**
 * quick_sort - Sort an array of ints in asc order using the quicksort
* @array: An array of integers.
* @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

lomuto_sort(array, size, 0, size - 1);
}
