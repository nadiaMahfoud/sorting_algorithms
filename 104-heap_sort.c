#include "sort.h"

void swap_elements(int *a, int *b);
void max_heapify_array(int *array, size_t array_size,
		size_t base_index, size_t root_index);
void heap_sort(int *array, size_t size);

/**
 * swap_elements -to  Swap 2 integers in an array.
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
 * max_heapify_array - to Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @array_size: The size of the array/tree.
 * @base_index: The index of the base row of the tree.
 * @root_index: The root node of the binary tree.
 */
void max_heapify_array(int *array, size_t array_size,
		size_t base_index, size_t root_index)
{
	size_t left_child, right_child, largest;

	left_child = 2 * root_index + 1;
	right_child = 2 * root_index + 2;
	largest = root_index;

	if (left_child < base_index && array[left_child] > array[largest])
		largest = left_child;
	if (right_child < base_index && array[right_child] > array[largest])
		largest = right_child;

	if (largest != root_index)
	{
		swap_elements(array + root_index, array + largest);
		print_array(array, array_size);
		max_heapify_array(array, array_size, base_index, largest);
	}
}

/**
 * heap_sort - to Sort an array of integers using the Heap Sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify_array(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_elements(array, array + i);
		print_array(array, size);
		max_heapify_array(array, size, i, 0);
	}
}

