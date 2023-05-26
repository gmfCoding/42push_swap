/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:36:50 by clovell           #+#    #+#             */
/*   Updated: 2023/05/25 13:15:27 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

/* RS: Rotate Stack
 * RRS: Reverse Rotate Stack
 * POS: Push to Other Stack
 */
# define RS 0
# define RRS 1
# define POS 3
# ifndef JS_STACK_SIZE
# define JS_STACK_SIZE 100
# endif

void	jump_sort(t_sort *sort)
{
	t_node	*start;
	int		moved;
	const t_opfunc	*ops = {op_rb, op_rrb};

	start = sort->a->head;
	moved = 0;
	while (moved < JS_STACK_SIZE || !start)
	{
		op_pb(sort);
		i++;
	}
	sort_stack(sort, sort->b, ops);
}

/* Finds the amounto rotations need to bring the smallest element to the top of the stack
 * Reverse rotations are values < 0
 */
static int	rotate_smallest(t_stack *stack, t_node *next, int forwards)
{
	int		min;
	int		rotations;
	int		rotated;

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
		next = next->prev;
		if (forwards)
			next = next->next->next;
		rotated--;
		if (forwards)
			rotated += 2;
	}
	if (rotated > (stack->count / 2))
		return (rotate_smallest(stack, stack->tail, 0));
	return (rotations);
}

static void sort_stack(t_sort *sort, t_stack *stack, t_opfunc *op[3])
{
	int rotations;

	while (stack->count > 0)
	{
		rotations = rotate_smallest(stack, stack->head, 1);
		while (rotations != 0)
		{
			if (rotations > 0)
				op[RS](sort);
			else
				op[RRS](sort);
			rotations--;
			if (rotations < 0)
				rotations += 2;
		}
		op[POS](sort);
	}
}
