#include <stdio.h>
#include "sort.h"

/**
 * print_list - Writes a list of integers
 *
 * @list: List to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
