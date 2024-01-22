#include "sort.h"

/**
 * bubble_sort - Sorted an array of integers using bubble sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int temp;

	if (!array || !size)
		return;

	while (i < size)
	{
		for (; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print(array, size);
			}
		}
		i++;
	}
}

