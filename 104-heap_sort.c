#include "sort.h"

/**
 * siftDown - Repair the heap
 * @array: heap to fix
 * @root: the root index of the heap
 * @end: the last index of the heap
 * @size: size of the heap
 *
 * Return: void
 */
void siftDown(int *array, size_t root, size_t end, size_t size)
{
	size_t leftChild, rightChild, swap;
	int tmp;

	while ((leftChild = (2 * root) + 1) <= end)
	{
		swap = root;
		rightChild = leftChild + 1;
		if (array[swap] < array[leftChild])
			swap = leftChild;
		if (rightChild <= end && array[swap] < array[rightChild])
			swap = rightChild;
		if (swap == root)
			return;
		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * heapify - Put elements of 'array' in heap order, in-place
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void heapify(int *array, size_t size)
{
	size_t parent;

	parent = ((size - 1) - 1) / 2;

	while (1)
	{
		siftDown(array, parent, size - 1, size);
		if (parent == 0)
			break;
		parent--;
	}
}

/**
 * heap_sort - function that sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int tmp;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		end--;
		siftDown(array, 0, end, size);
	}
}
