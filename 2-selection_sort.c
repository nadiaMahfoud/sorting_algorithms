#include "sort.h"

/**
 * swap_int -To  Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - to sort an array of integers in ascending order
 * @array: The array
 * @size: The size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int *minval;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minval = array + i;
		for (j = i + 1; j < size; j++)
			minval = (array[j] < *minval) ? (array + j) : minval;

		if ((array + i) != minval)
		{
			swap_int(array + i, minval);
			print_array(array, size);
		}
	}
}
