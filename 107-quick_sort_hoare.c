#include "sort.h"

/**
 * swap_values -to Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_values(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition_hoare - to  Order a subset of an array.
 * @arr: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 * Return: The final partition index.
 */
int partition_hoare(int *arr, size_t size, int low, int high)
{
	int pivot, above, below;

	pivot = arr[high];
	for (above = low - 1, below = high + 1; above < below;)
	{
		do {
			above++;
		} while (arr[above] < pivot);
		do {
			below--;
		} while (arr[below] > pivot);

		if (above < below)
		{
			swap_values(arr + above, arr + below);
			print_array(arr, size);
		}
	}

	return (above);
}

/**
 * sort_hoare - to Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 */
void sort_hoare(int *arr, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition_hoare(arr, size, low, high);
		sort_hoare(arr, size, low, part - 1);
		sort_hoare(arr, size, part, high);
	}
}

/**
 * quick_sort_hoare - to Sort an array of integers
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_hoare(array, size, 0, size - 1);
}

