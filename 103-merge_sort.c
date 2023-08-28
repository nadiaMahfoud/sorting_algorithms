#include "sort.h"

/**
 * copy_data - to copy data from one buffer to another
 *
 * @source: source buffer
 * @destination: destination buffer
 * @size: size of buffers
 *
 * Return: No Return
 */
void copy_data(int *source, int *destination, int size)
{
	int i;

	for (i = 0; i < size; i++)
		destination[i] = source[i];
}

/**
 * merge_arrays - to merge two sets of data in ascending order
 * but they must already be sorted beforehand
 * @array: first set of data
 * @buffer: second set of data
 * @min_left: lower range of first set of data
 * @max_left: upper range of first set of data
 * @min_right: lower range of second set of data
 * @max_right: upper range of second set of data
 *
 * Return: No Return
 */
void merge_arrays(int *array, int *buffer, int min_left,
		int max_left, int min_right, int max_right)
{
	int i = min_left, j = min_right, k = min_left;

	while (i <= max_left || j <= max_right)

		if (i <= max_left && j <= max_right)
			if (buffer[i] <= buffer[j])
				array[k] = buffer[i], k++, i++;
			else
				array[k] = buffer[j], k++, j++;

		else if (i > max_left && j <= max_right)
			array[k] = buffer[j], k++, j++;
		else
			array[k] = buffer[i], k++, i++;
}

/**
 * print_range - to print an array in a given range
 *
 * @array: array of data to be printed
 * @start: start of range
 * @end: end of range
 *
 * Return: No Return
 */
void print_range(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * split_array - to recursive function to split data into a merge tree
 *
 * @array: array of data to be split
 * @buffer: auxiliary array of data for merging
 * @min: min range of data in array
 * @max: max range of data in array
 * @size: size of total data
 *
 * Return: No Return
 */
void split_array(int *array, int *buffer, int min, int max, int size)
{
	int mid, max_temp, min_left, max_left, min_right, max_right;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	max_temp = max;
	max = mid - 1;

	min_left = min;
	max_left = max;

	split_array(array, buffer, min, max, size);

	min = mid;
	max = max_temp;

	min_right = min;
	max_right = max;

	split_array(array, buffer, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	print_range(array, min_left, max_left);

	printf("[right]: ");

	print_range(array, min_right, max_right);
	merge_arrays(array, buffer, min_left, max_left, min_right, max_right);
	copy_data(array, buffer, size);

	printf("[Done]: ");
	print_range(array, min_left, max_right);
}

/**
 * merge_sort -to  sort an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	copy_data(array, buffer, size);

	split_array(array, buffer, 0, size - 1, size);

	free(buffer);
}

