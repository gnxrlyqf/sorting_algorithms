#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sort an array in ascending order using the bubble algorithm
 * @array: array to sort
 * @size: size of the array
*/

void bubble_sort(int *array, size_t size)
{
	unsigned long int i, unsorted = 1, temp;

	if (size < 2 || !array)
		return;
	while (unsorted)
	{
		unsorted = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				unsorted = 1;
				print_array(array, size);
			}
		}
	}
}
