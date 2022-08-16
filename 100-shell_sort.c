#include "sort.h"

/**
 * _swap - swaps two values
 * @array: array of integers
 * @i: first index
 * @j: second index
 */

void _swap(int *array, int i, int j)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}


/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of the array
 *
 *
 * Desc: prints the array each time you decrease the interval
 */

void shell_sort(int *array, size_t size)
{
	size_t h = 0,  i, j;

	if (size < 2)
	{
		return;
	}

	while (h <= size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
				_swap(array, j, j - h);
		h /= 3;
		print_array(array, size);
	}
}
