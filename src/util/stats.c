/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42adel.org.au>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:36:21 by clovell           #+#    #+#             */
/*   Updated: 2023/07/20 17:52:57 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include <limits.h>

/* Gets the largest value in the stack smaller than or equal to 'max' */
int	stat_largest(t_stack *stack, int max)
{
	t_node	*next;
	int		cand;

	cand = INT_MIN;
	next = stack->head;
	while (next)
	{
		if (next->value > cand && next->value <= max)
			cand = next->value;
		next = next->next;
	}
	return (cand);
}

/* Gets the smallest value in the stack larger than or equal to min */
int	stat_smallest(t_stack *stack, int min)
{
	t_node	*next;
	int		cand;

	cand = INT_MAX;
	next = stack->head;
	while (next)
	{
		if (next->value < cand && next->value >= min)
			cand = next->value;
		next = next->next;
	}
	return (cand);
}
