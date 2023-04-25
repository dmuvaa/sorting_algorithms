#include "sort.h"

/**
 * shell_sort - Sorts an array of integers
 * @array: Pointer to the array of integers to be sorted
 * @size: Number of elements in the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Knuth sequence for gap */
	for (gap = 1; gap < size; gap = gap * 3 + 1)
		;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
