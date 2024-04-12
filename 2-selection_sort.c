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
* selection_sort - Sort an array of int in asc order by selection sort
* @array: An array of integers.
* @size: The size of the array.
* Description: Prints the array after each swap.
*/
void selection_sort(int *array, size_t size)
{
int *n;
size_t i, j;

if (array == NULL || size < 2)
return;

for (i = 0; i < size - 1; i++)
{
n = array + i;
for (j = i + 1; j < size; j++)
n = (array[j] < *n) ? (array + j) : n;
if ((array + i) != n)
{
swap(array + i, n);
print_array(array, size);
}
}
}
