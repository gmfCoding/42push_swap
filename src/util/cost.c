#include <limits.h>
#include "stack.h"

/* Finds the amount of rotations
 * needed to bring the largest element to the top of the stack
 * Reverse rotations are values < 0
 */
int rotate_largest(t_stack *stack, t_node *next, int forwards)
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
}

/* Finds the amount of rotations
 * needed to bring the smallest element to the top of the stack
 * Reverse rotations are values < 0
 */
int rotate_smallest(t_stack *stack, t_node *next, int forwards)
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
		return (rotate_smallest(stack, stack->tail, 0) - 1);
	return (rotations);
}

int rotate_target(t_stack *stack, t_node *next, int target, int forwards)
{
	int rotated;

	rotated = 0;
	while (next)
	{
		if (next->value == target)
			break ;
		if (forwards)
			next = next->next;
		else
			next = next->prev;
		rotated += 1 + ((forwards == 0) * -2);
	}
	if (rotated > (stack->count / 2))
		return (rotate_target(stack, stack->tail, target, 0) - 1);
	return (rotated);
}
