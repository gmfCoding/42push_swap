/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helm_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:24:28 by clovell           #+#    #+#             */
/*   Updated: 2023/06/07 12:33:09 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "sort.h"
#include "stack.h"
#include "pivot.h"
#include "util.h"

/* Finds the amount of rotations
 * needed to bring the largest element to the top of the stack
 * Reverse rotations are values < 0
 */
/*
static int	rotate_largest(t_stack *stack, t_node *next, int max, int forwards)
{
	int		curr;
	int		rotations;
	int		rotated;

	curr = INT_MIN;
	rotations = 0;
	rotated = 0;
	while (next)
	{
		if (next->value > curr && next->value <= max)
		{
			curr = next->value;
			rotations = rotated;
		}
		if (forwards)
			next = next->next;
		else
			next = next->prev;
		rotated += 1 + ((forwards == 0) * -2);
	}
	if (rotations > (stack->count / 2))
		return (rotate_largest(stack, stack->tail, max, 0));
	return (rotations);
}
*/
static int rotate_largest(t_stack *stack, t_node *next, int forwards)
{
	int	min;
	int rotations;
	int rotated;

	min = INT_MIN;
	rotations = 0;
	rotated = 0;
	while (next)
	{
		if (next->value > min)
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
		return (rotate_largest(stack, stack->tail, 0) - 1);
	return (rotations);
}/*
static int rotate_smallest(t_stack *stack, t_node *next, int forwards)
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
void	push_back(t_sort *sort)
{
	int	rotations;

	while (sort->b->count > 0)
	{
		rotations = rotate_largest(sort->b, sort->b->head, 1);
		while (rotations != 0)
		{
			if (rotations < 0)
				op_rrb(sort);
			else
				op_rb(sort);
			rotations += ((rotations < 0) - (rotations > 0));
		}
		op_pa(sort);
	}
}

/* Finds the smallest value in 'stack' that is larger than min. 
int	get_smallest(t_stack *stack, int min)
{
	t_node	*next;
	int		cand;

	cand = INT_MAX;
	next = stack->head;
	while (next)
	{
		if (next->value < cand & next->value > min)
			cand = next->value;
		next = next->next;
	}
	return (cand);
}*/
void	stn_print(t_sort *sort);


#include <unistd.h> // BAD INCLUDE
#include <stdio.h> // BAD

/* Helm sort:
 * Sort stack 'A' using the following approach:
 * Let 'n' be the amount of elements in the stack
 * Let 'b' be the bucket size.
 * Move the 'n/b' largest integers into 'B'
 * The move from stack 'B' move the largest back into 'A'
 */
void	helm_sort(t_sort *sort)
{
	const int	quatre = (sort->a->count / 4) + (sort->a->count < 4);
	int			pushed;
	int			max;
	int			min;
	int			rotations;

	t_median	*med;
	int			place;

	place = quatre;
	med = create_median(sort->a);
	min = INT_MIN;
	printf("size:%d quatre: %d ", sort->a->count, quatre); // BAD
	while (!is_sorted(sort))
	{
		rotations = 0;
		pushed = 0;
		max = get_smallest(med, place);
		printf("min:%d max:%d place:%d\n", min, max, place); // BAD
		while (rotations < sort->a->count && sort->a->count > 0)
		{
			if (sort->a->head->value <= max && sort->a->head->value >= min)
			{
				op_pb(sort);
				pushed++;
			}
			else
			{
				op_ra(sort);
				rotations++;
			}
		}
		printf("pre_push_back:\n");
		stn_print(sort);
		min = get_smallest(med, place + 1);
		push_back(sort);
		printf("post_push_back:\n");	
		stn_print(sort);
		place += pushed;
		//if (place - quatre > quatre * 3)
			//	break ;
		while (pushed > 0)
		{
			op_ra(sort);
			pushed--;
		}
		printf("post_rotate:\n");
		stn_print(sort);
		usleep(1000000); // BAD FUNCTION, DO NOT USE.
	}
	printf("Done\n\n!");
	if (is_sorted(sort))
		printf("Successfull sorted\n\n!");
	med_delete(&med);
}
