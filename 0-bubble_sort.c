#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len;
	int tmp, flag = 1;

	if (array == NULL || size < 2)
		return;

	len = size;

	while (flag != 0)
	{
		flag = 0;

		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				flag = 1;
				print_array(array, size);
			}
		}
		len -= 1;
	}
}
