/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:08:56 by clovell           #+#    #+#             */
/*   Updated: 2023/05/29 17:25:07 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pivot.h"
#include "stack.h"
#include "libft.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

static int	partition(t_median *median, int left, int right)
{
	const int	val = median->array[right];
	int			i;
	int			j;

	i = left;
	j = left;
	while (j < right)
	{
		if (median->array[j] < val)
		{
			swap(&median->array[i], &median->array[j]);
			i++;
		}
		j++;
	}
	swap(&median->array[i], &median->array[j]);
	return (i);
}

static void	median_correct(t_median *median, int left, int right, int select)
{
	int	p_index;

	if (left < right)
	{
		swap(&median->array[median->size / 2], &median->array[right]);
		p_index = partition(median, left, right);
		if (p_index == select)
		{
			median->num2 = median->array[p_index];
			if (median->num1 != -1)
				return ;
		}
		else if (p_index == select - 1)
		{
			median->num1 = median->array[p_index];
			if (median->num2 != -1)
				return ;
		}	
		if (p_index >= select)
			return (median_correct(median, left, p_index - 1, select));
		else
			return (median_correct(median, left, p_index + 1, select));
	}
}

int	median(t_median *median)
{
	median->num1 = -1;
	median->num2 = -1;
	median_correct(median, 0, median->size - 1, median->size / 2);
	if (median->size % 2 == 0)
		median->answer = (median->num1 + median->num2) / 2;
	else
		median->answer = median->num2;
	return (median->answer);
}

t_median	*median_from_stack(t_stack *stack)
{
	int			size;
	t_median	*med;
	t_node		*curr;

	curr = stack->head;
	size = 0;
	while (curr)
	{
		curr = curr->next;
		size++;
	}
	med = ft_calloc(sizeof(t_median), 1);
	med->array = ft_calloc(sizeof(int), size);
	curr = stack->head;
	med->size = size;
	size = 0;
	while (curr)
	{
		med->array[size++] = curr->value;
		curr = curr->next;
	}
	return (med);
}
