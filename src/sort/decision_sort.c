#include <limits.h>
#include "sort.h"
#include "stack.h"
#include "pivot.h"
#include "util.h"
#include "program.h"
#include "util.h"

void stn_print(t_sort *sort);

typedef struct s_rotinfo t_rotinfo;

void apply_rotation(t_sort *sort, t_stack *stack, int amount)
{
	while (amount != 0)
	{
		if (sort->b == stack)
		{
			if (amount < 0)
				op_rrb(sort);
			else
				op_rb(sort);
		}
		else
		{
			if (amount < 0)
				op_rra(sort);
			else
				op_ra(sort);
		
		}
		if (amount > 0)
			amount--;
		else
			amount++;
	}
}
static int value_largest(t_stack *stack)
{
	int	min;
	t_node *next;

	min = INT_MIN;
	next = stack->head;
	while (next)
	{
		if (next->value > min)
			min = next->value;
		next = next->next;
	}
	return (min);
}

struct s_rotinfo
{
	int swaps;
	int apply[2];
	int rotations[2];
};

t_rotinfo	decide_rotate(t_stack *stack, t_median *med, int value)
{
	int first;
	int second;

	// Call the rotate_target with med_next/prev multiple times to find and accumulates the value to compare and other stuff
	first = rotate_target(stack, stack->head, med_first_value_lte(med, value), 0);
	second = rotate_target(stack, stack->head, median_prev(med, value), 0);
	if (((first > 0 && first < second) || (first <= 0 && first > second)))
		return ((t_rotinfo){0, {0, 0}, {first, 0}});
	return ((t_rotinfo){1, {1, 0}, {first, second}});
}

static void	push_back(t_sort *sort)
{
	t_rotinfo info;
	
	t_median *med;
	info = (t_rotinfo){-1, {0, 0}, {0, 0}};
	med = create_median(sort->b);
	while (sort->b->count > 0)
	{
		if (info.swaps == -1)
			info = decide_rotate(sort->b, med, value_largest(sort->b));
		apply_rotation(sort, sort->b, info.rotations[info.swaps]);
		op_pa(sort);
		if (info.swaps >= 0 && info.apply[info.swaps])
			op_sa(sort);
		info.swaps--;
	}
}

#include <stdio.h>



void push_to_b(t_sort *sort, int reverse, int min, int max)
{
	int position;
	int count;

	count = sort->a->count;
	position = 0;
	while (position < count)
	{
		if (sort->a->head->value >= min && sort->a->head->value <= max)
			op_pb(sort);
		else if (reverse)
			op_rra(sort);
		else
			op_ra(sort);
		position++;
	}
}

void decision_sort(t_sort *sort)
{
	const int	quatre = (sort->a->count / 8) + (sort->a->count < 8);
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
		//usleep(1000000); // BAD FUNCTION, DO NOT USE.
	}
	printf("Done\n\n!");
	if (is_sorted(sort))
		printf("Successfull sorted\n\n!");
	med_delete(&med);
	
}
