/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helm_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:24:28 by clovell           #+#    #+#             */
/*   Updated: 2023/05/26 19:28:54 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "sort.h"
#include "stack.h"

/* Finds the amount of rotations
 * needed to bring the largest element to the top of the stack
 * Reverse rotations are values < 0
 */
static int	rotate_largest(t_stack *stack, t_node *next, int upper, int forwards)
{
	int		max;
	int		rotations;
	int		rotated;

	max = INT_MIN;
	rotations = 0;
	rotated = 0;
	while (next)
	{
		if (next->value > max && next->value <= upper)
		{
			max = next->value;
			rotations = rotated;
		}
		if (forwards)
			next = next->next;
		else
			next = next->prev;
		rotated += 1 + ((forwards == 0) * -2);
	}
	if (rotations > (stack->count / 2))
		return (rotate_largest(stack, stack->tail, upper, 0));
	return (rotations);
}

/*
 * static int rotate_smallest(t_stack *stack, t_node *next, int forwards)
{
	int	min;
	int rotations;
	int rotated;

	min = INT_MAX;
	rotations = 0;
	rotated = 0;
	while (next)
	{
		if (next->value < min)
		{
			min = next->value;
			rotations = rotated;
		}
		if (forwards)
			next = next->next;
		else
			next = next->prev;
		rotated += 1 + ((forwards == 0) * -2);
	}
	if (rotations > (stack->count / 2))
		return (rotate_smallest(stack, stack->tail, 0));
	return (rotations);
}
*/
int find_smallest(t_stack *stack)
{
	t_node *next;
	int		min;

	next = stack->head;
	min = INT_MAX;
	while (next)
	{
		if (next->value < min)
			min = next->value;
		next = next->next;
	}	
	return (min);
}

void push_back(t_sort *sort)
{
	int rotations;

	while (sort->b->count > 0)
	{
		rotations = rotate_largest(sort->b, sort->b->head, INT_MAX, 1);
		while (rotations != 0)
		{
			if (rotations < 0)
				op_rrb(sort);
			else
				op_rb(sort);
			rotations  += ((rotations < 0) - (rotations > 0));
		}
		op_pa(sort);
	}
}

/* Helm sort:
 * Sort stack 'A' using the following approach:
 * Let 'n' be the amount of elements in the stack
 * Let 'b' be the bucket size.
 * Move the 'n/b' largest integers into 'B'
 * The move from stack 'B' move the largest back into 'A'
 */
void helm_sort(t_sort *sort)
{
	int	pushed;
	int	rotations;
	int min;

	pushed = 0;
	rotations = 0;
	min = INT_MAX;
	while (!is_sorted(sort))
	{
		while (pushed < 25 && sort->a->count > 0)
		{
			rotations = rotate_largest(sort->a, sort->a->head, min, 1);
			while (rotations != 0)
			{
				if (rotations < 0)
					op_rra(sort);
			   	else
					op_ra(sort);
				rotations += ((rotations < 0) - (rotations > 0));
			}
			op_pb(sort);
			pushed++;	
		}
		pushed = 0;
		min = find_smallest(sort->b) - 1;
		push_back(sort);	
	}
}
