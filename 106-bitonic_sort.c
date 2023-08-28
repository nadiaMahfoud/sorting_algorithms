#include "sort.h"

void swap_elements(int *a, int *b);
void merge_bitonic(int *array, size_t array_size, size_t start_index,
		size_t seq_size, char order);
void build_bitonic_sequence(int *array, size_t array_size, size_t start_index,
		size_t seq_size, char order);
void bitonic_sort(int *array, size_t size);

/**
 * swap_elements -to  Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_elements(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * merge_bitonic - to Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @array_size: The size of the array.
 * @start_index: The starting index of the sequence in array to sort.
 * @seq_size: The size of the sequence to sort.
 * @order: The direction to sort in.
 */
void merge_bitonic(int *array, size_t array_size, size_t start_index,
		size_t seq_size, char order)
{
	size_t i, jump = seq_size / 2;

	if (seq_size > 1)
	{
		for (i = start_index; i < start_index + jump; i++)
		{
			if ((order == 'U' && array[i] > array[i + jump]) ||
			    (order == 'D' && array[i] < array[i + jump]))
				swap_elements(array + i, array + i + jump);
		}
		merge_bitonic(array, array_size, start_index, jump, order);
		merge_bitonic(array, array_size, start_index + jump, jump, order);
	}
}

/**
 * build_bitonic_sequence - to Convert an array of integers
 * into a bitonic sequence.
 * @array: An array of integers.
 * @array_size: The size of the array.
 * @start_index: The starting index of a block of
 * the building bitonic sequence.
 * @seq_size: The size of a block of the building bitonic sequence.
 * @order: The direction to sort the bitonic sequence block in.
 */
void build_bitonic_sequence(int *array, size_t array_size,
		size_t start_index, size_t seq_size, char order)
{
	size_t cut = seq_size / 2;
	char *direction = (order == 'U') ? "UP" : "DOWN";

	if (seq_size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq_size, array_size, direction);
		print_array(array + start_index, seq_size);

		build_bitonic_sequence(array, array_size, start_index, cut, 'U');
		build_bitonic_sequence(array, array_size, start_index + cut, cut, 'D');
		merge_bitonic(array, array_size, start_index, seq_size, order);

		printf("Result [%lu/%lu] (%s):\n", seq_size, array_size, direction);
		print_array(array + start_index, seq_size);
	}
}

/**
 * bitonic_sort - to Sort an array of integers
 * using the Bitonic Sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	build_bitonic_sequence(array, size, 0, size, 'U');
}

