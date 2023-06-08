#include <stdlib.h>
#include "pivot.h"
#include "libft.h"

void	median_insertion_sort(t_median *med, int n)
{
	int i;
	int key;
	int j;

	i = 1;
	while (i < n)
	{
		key = med->array[i];
		j = i - 1;
		while (j >= 0 && med->array[j] > key)
		{
			med->array[j + 1] = med->array[j];
			j--;
		}
		med->array[j + 1] = key;
		i++;
	}
}

t_median *create_median(t_stack *stack)
{
	t_node		*curr;
	t_median	*med;
	int			size;

	size = 0;
	med = ft_calloc(sizeof(t_median), 1);
	curr = stack->head;
	while (curr)
	{
		curr = curr->next;
		size++;
	}
	med->array = ft_calloc(sizeof(int), size);
	med->size = size;
	curr = stack->head;
	size = 0;
	while (curr)
	{
		med->array[size++] = curr->value;
		curr = curr->next;
	}
	median_insertion_sort(med, med->size);
	return (med);
}

int	get_smallest(t_median *median, int kth)
{
	if (kth < 0)
		kth = 0;
	if (kth >= median->size)
		kth = median->size - 1;
	return (median->array[kth]);
}

void	med_delete(t_median **median)
{
	free((*median)->array);
	free(*median);
	*median = NULL;
}
