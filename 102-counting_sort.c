#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, tmp, max = 0, sum = 0;
	int *count, *copy;

	if (array == NULL || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		copy[i] = array[i];
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(copy);
		return;
	}
	for (j = 0; j <= max; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] = 1;
	for (j = 0; j <= max; j++)
	{
		tmp = count[j];
		count[j] = sum;
		sum += tmp;
	}
	for (i = 0; i < size; i++)
	{
		array[count[copy[i]]] = copy[i];
		count[copy[i]] += 1;
	}
	print_array(count, max + 1);
	free(copy);
	free(count);
}
