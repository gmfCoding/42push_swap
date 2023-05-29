/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:45:11 by clovell           #+#    #+#             */
/*   Updated: 2023/05/29 14:28:47 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"
#include "ft_printf.h"
#include <limits.h>

int	find_smallest(t_stack *stack)
{
	t_node	*node;
	int		min;
	int		min_rotations;
	int		rotations;

	rotations = 0;
	node = stack->head;
	min = INT_MAX;
	while (node)
	{
		if (node->value < min)
		{
			min_rotations = rotations;
			min = node->value;
		}
		node = node->next;
		rotations++;
	}
	return (min_rotations);
}

void	bubble_sort(t_sort *sort)
{
	int	rotations;
	int	current;

	while (sort->a->head)
	{
		current = 0;
		rotations = find_smallest(sort->a);
		while (current < rotations)
		{
			op_ra(sort);
			current++;
		}
		op_pb(sort);
	}
	while (sort->b->head)
	{
		op_pa(sort);
	}
}
