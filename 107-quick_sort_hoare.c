#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Exchange the positions of two
 * integers within an array.
 * @a: The first integer to be interchanged.
 * @b: The second integer to be interchanged.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Rearrange a segment of an array of integers
 *                   following the Hoare partitioning scheme.
 * @array: The array containing integers.
 * @size: The size of the array.
 * @left: The starting index of the segment to be rearranged.
 * @right: The ending index of the segment to be rearranged.
 *
 * Return: The final index of the partition.
 *
 * Description: Employs the last element of the segment as the pivot.
 * Prints the array after each exchange of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Apply the quicksort algorithm recursively.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the partition to be sorted.
 * @right: The ending index of the partition to be sorted.
 *
 * Description: Utilizes the Hoare partitioning scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Arrange an array of integers in ascending
 *			order utilizing the quicksort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Employs the Hoare partitioning scheme. Prints
 * the array after each exchange of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
