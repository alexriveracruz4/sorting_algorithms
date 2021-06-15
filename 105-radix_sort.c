#include "sort.h"

/**
 * getMax - get max value of an array
 * @array: array
 * @size: size of array
 *
 * Return: max value of array
 */
int getMax(int *array, int size)
{
	int max, i;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - Sort digits in ascending order using count sort algorithm
 * @array: array of itegers
 * @size: size of array
 * @digit: digit to sort
 * @sorted: a buffer to store the sorted array
 *
 * Return: void
 */
void countSort(int *array, size_t size, int digit, int *sorted)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / digit) % 10] += 1;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		sorted[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];
}
/**
 * radix_sort - function that sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, digit, *sorted;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	max = getMax(array, size);
	for (digit = 1; max / digit > 0; digit *= 10)
	{
		countSort(array, size, digit, sorted);
		print_array(array, size);
	}
	free(sorted);
}
