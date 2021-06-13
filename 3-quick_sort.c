#include "sort.h"

/**
 * lomuto_partition - function thath finds the pivot for partition
 * @array: array to be sorted
 * @lo: lowest index of partition sort
 * @hi: high index of partition sort
 * @size: size of the array
 *
 * Return: void
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[hi];
	i = lo;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[hi] < array[i])
	{
		tmp = array[i];
		array[i] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i);
}



/**
 * lomuto_sort - function that sorts a partition of array
 * @array: array to be sorted
 * @lo: lowest index of partition sort
 * @hi: highest index of partition sort
 * @size: size of the array
 *
 * Return: void
 */
void lomuto_sort(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = lomuto_partition(array, lo, hi, size);
		lomuto_sort(array, lo, pivot - 1, size);
		lomuto_sort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, 0, size - 1, size);
}
