#include "sort.h"

/**
 * swap_int -To  Swap two integers in an array.
 * @a: The first int to swap.
 * @b: The second int to swap.
 */

void swap_int(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * bubble_sort -To  Sort an array of integers in ascending order.
 *
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, leng = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < leng - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_int(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		leng--;
	}
}
