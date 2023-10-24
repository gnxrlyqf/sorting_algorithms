#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - initiates the quick sort algorithm
 * @array: array to sort
 * @size: size of array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	actual_quick_sort(array, 0, size - 1, size);
}

/**
 * actual_quick_sort - sorts a subarray in ascending order using quick sort
 * @array: array to sort
 * @start: starting index of subarray
 * @end: end index of subarray
 * @size: size of array
*/

void actual_quick_sort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;
	pivot = part(array, start, end, size);
	actual_quick_sort(array, start, pivot - 1, size);
	actual_quick_sort(array, pivot + 1, end, size);
}

/**
 * part - partitions a subarray using the Lomuto partition scheme
 * @array: subarray to part
 * @start: start index of subarray
 * @end: end index of subarray
 * @size: size of array
 *
 * Return: index of the pivot
*/

int part(int *array, int start, int end, size_t size)
{
	int pivot = array[end], j = start - 1, i;

	for (i = start; i <= end - 1; i++)
	{
		if (array[i] < pivot)
			j++, swap(array, i, j, size);
	}
	j++, swap(array, end, j, size);
	return (j);
}

/**
 * swap - swaps two elements in an array
 * @array: array to process
 * @input1: element to swap
 * @input2: element to swap
 * @size: size of array
*/

void swap(int *array, int input1, int input2, size_t size)
{
	int temp;

	if (input1 == input2)
		return;
	temp = array[input2];
	array[input2] = array[input1];
	array[input1] = temp;
	print_array(array, size);
}
