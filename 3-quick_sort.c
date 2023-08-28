#include "sort.h"

void swap_int(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_int -to  Swap 2 integers in an array.
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
 * lomuto_partition -To  Order a subset of an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, ab, bel;

	pivot = array + right;
	for (ab = bel = left; bel < right; bel++)
	{
		if (array[bel] < *pivot)
		{
			if (ab < bel)
			{
				swap_int(array + bel, array + ab);
				print_array(array, size);
			}
			ab++;
		}
	}

	if (array[ab] > *pivot)
	{
		swap_int(array + ab, pivot);
		print_array(array, size);
	}

	return (ab);
}

/**
 * lomuto_sort - To Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partit;

	if (right - left > 0)
	{
		partit = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partit - 1);
		lomuto_sort(array, size, partit + 1, right);
	}
}

/**
 * quick_sort - to Sort an array using the quick sort algorithm
 * and Lomuto's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
