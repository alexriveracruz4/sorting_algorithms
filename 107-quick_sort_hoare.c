#include "sort.h"

/**
 * hoarePartition - finds the partition for the quicksort
 * @array: array to be sorted
 * @lo: lowest index of partition
 * @hi: highest index of partition
 * @size: size of the array
 *
 * Return: index of partition
 */
int hoarePartition(int *array, int lo, int hi, size_t size)
{
	int pivot, tmp, i, j;

	pivot = array[(lo + hi) / 2];
	i = lo - 1;
	j = hi + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);


		if (i >= j)
			return (j);
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * hoareSort - sort the partition of the array
 * @array: array to be sorted
 * @lo: lowest index of the partition
 * @hi: highest index of teh partition
 * @size: size of array
 *
 * Return: void
 */
void hoareSort(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = hoarePartition(array, lo, hi, size);
		hoareSort(array, lo, pivot, size);
		hoareSort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort_hoare - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoareSort(array, 0, size - 1, size);
}
