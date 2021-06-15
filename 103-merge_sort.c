#include "sort.h"
#include <stdio.h>

/**
 * sort_subarr - sort and merge sub array
 * @start: start index of left sub array
 * @mid: final index of left sub array and start index for right sub array
 * @final: final index of right sub array
 * @in: input subarray
 * @out: output subarray
 *
 * Return: void
 */
void sort_subarr(size_t start, size_t mid, size_t final, int *out, int *in)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(in + start, mid - start);
	printf("[right]: ");
	print_array(in + mid, final - mid);
	i = start;
	j = mid;
	for (k = start; k < final; k++)
	{
		if (i < mid && (j >= final || in[i] <= in[j]))
		{
			out[k] = in[i];
			i++;
		}
		else
		{
			out[k] = in[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(out + start, final - start);
}

/**
 * sort_recursive - Implement the merge sort algorithm through recursion
 * @start: start index
 * @final: final index
 * @in: input array
 * @out: output array
 *
 * Return: void
 */
void sort_recursive(size_t start, size_t final, int *in, int *out)
{
	size_t mid;

	if (final - start < 2)
		return;
	mid = (start + final) / 2;
	sort_recursive(start, mid, in, out);
	sort_recursive(mid, final, in, out);
	sort_subarr(start, mid, final, in, out);
	for (mid = start; mid < final; mid++)
		out[mid] = in[mid];
}

/**
 * merge_sort - function that sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	sort_recursive(0, size, array, copy);
	free(copy);
}
