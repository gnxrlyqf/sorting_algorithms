#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order using selection
 * @array: array to sort
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, min, temp, swap;

	for (i = 0; i < size; i++)
	{
		min = i, swap = 0;
		for (j = i; j < size; j++)
			if (array[j] < array[min])
				min = j, swap = 1;
		if (swap)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
