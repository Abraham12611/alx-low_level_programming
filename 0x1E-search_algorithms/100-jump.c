
Sign up
This repository has been archived by the owner on Aug 11, 2022. It is now read-only.
B3zaleel
/
alx-low_level_programming
Public archive
Code
Issues
Pull requests
Actions
Projects
Security
Insights
alx-low_level_programming/0x1E-search_algorithms/100-jump.c
@B3zaleel
B3zaleel Fix compilation issue
 1 contributor
36 lines (34 sloc)  901 Bytes
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches a value in a sorted array using a jump search.
 * @array: The array to search in.
 * @size: The length of the array.
 * @value: The value to look for.
 *
 * Return: The index of the value in the array, otherwise -1.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, a = 0, b = 0;

	if (!array)
		return (-1);
	step = (size_t)sqrt(size);
	while ((b < size) && (*(array + b) < value))
	{
		printf("Value checked array[%d] = [%d]\n", (int)b, *(array + b));
		a = b;
		b += step;
		if (a >= size)
			return (-1);
	}
	printf("Value found between indexes [%d] and [%d]\n", (int)a, (int)b);
	b = b >= size ? size - 1 : b;
	for (; (a <= b) && (*(array + a) <= value); a++)
	{
		printf("Value checked array[%d] = [%d]\n", (int)a, *(array + a));
		if (*(array + a) == value)
			return ((int)a);
	}
	return (-1);
}
