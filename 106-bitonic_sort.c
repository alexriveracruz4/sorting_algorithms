#include "sort.h"
#include <stdio.h>

/**
 * bitMerge - Sort a bitonic sequence inside an array of integers
 * @array: array of ints
 * @size: soze of the array
 * @lowIdx: starting index of the sequence in array to sort
 * @count: size of the sequence to sort
 * @dir: direction to sort in
 *
 * Return: void
 */
void bitMerge(int *array, size_t size, size_t lowIdx, size_t count, char dir)
{

	size_t i, k = count / 2;
	int tmp;

	if (count > 1)
	{
		for (i = lowIdx; i < lowIdx + k; i++)
		{
			if (dir == (array[i] > array[i + k]))
			{
				tmp = array[i];
				array[i] = array[i + k];
				array[i + k] = tmp;
			}
		}
		bitMerge(array, size, lowIdx, k, dir);
		bitMerge(array, size, lowIdx + k, k, dir);
	}
}

/**
 * bitonic - Convert an array of integers into a bitonic sequence
 * @array: array of ints
 * @size: size of teh array
 * @lowIdx: starting index of a block of the building bitonic sequence
 * @count: size of a block of the building bitonic sequence
 * @dir: The direction to sort the bitonic sequence block in
 *
 * Return: void
 */
void bitonic(int *array, size_t size, size_t lowIdx, size_t count, char dir)
{

	size_t k = count / 2;
	char *str = (dir == 1) ? "UP" : "DOWN";

	if (count > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", count, size, str);
		print_array(array + lowIdx, count);

		bitonic(array, size, lowIdx, k, 1);
		bitonic(array, size, lowIdx + k, k, 0);
		bitMerge(array, size, lowIdx, count, dir);

		printf("Result [%lu/%lu] (%s):\n", count, size, str);
		print_array(array + lowIdx, count);
	}
}

/**
 * bitonic_sort - function that sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of teh array
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic(array, size, 0, size, 1);
}
