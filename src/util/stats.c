#include "stack.h"
#include <limits.h>

/* Gets the largest value in the stack smaller than or equal to 'max' */
int    stat_largest(t_stack *stack, int max)
{
	t_node  *next;
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
int    stat_smallest(t_stack *stack, int min)
{
	t_node  *next;
	int			  cand;
	
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

