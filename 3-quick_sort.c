#include "sort.h"

/**
 * swap - Swaps tow integer values.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * lomuto_partition - Partition the array using lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The starting index of the array partitions.
 * @high: The ending index of the array partitions.
 *
 * Return: The partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int i = low, j, pivot = array[high];

	for (i = j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j]);
			print_array((const int *)array, size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	print_array((const int *)array, size);
	return (i);
}

/**
 * quickSort - Sorted partitions of the array using lomuto.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The starting index of the array partitions.
 * @high: The ending index of the array partitions.
 */
void quickSort(int *array, size_t size, int low, int high)
{
	size_t partition_i;

	if (low < high)
	{
		partition_i = lomuto_partition(array, size, low, high);
		quickSort(array, size, low, partition_i - 1);
		quickSort(array, size, partition_i + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integer using Quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || !size)
		return;
	quickSort(array, size, 0, size - 1);
}
