#include "sort.h"

int get_maximum(int *array, int size);
void radix_count_sort(int *array, size_t size, int significant, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * get_maximum - to Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int get_maximum(int *array, int size)
{
	int max_val, i;

	for (max_val = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}

	return (max_val);
}

/**
 * radix_count_sort -to  Sort the significant digits.
 * @array: An array of integers.
 * @size: The size of the array.
 * @significant: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void radix_count_sort(int *array, size_t size, int significant, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / significant) % 10] += 1;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / significant) % 10] - 1] = array[i];
		count[(array[i] / significant) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - to Sort an array of integers using the Radix Sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_value, significant, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max_value = get_maximum(array, size);
	for (significant = 1; max_value / significant > 0; significant *= 10)
	{
		radix_count_sort(array, size, significant, buffer);
		print_array(array, size);
	}

	free(buffer);
}

