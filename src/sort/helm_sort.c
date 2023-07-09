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
#include "debug.h" //REMOVE

typedef struct s_helm_sort t_hs;
typedef struct s_helm_sort_sub t_hss;

struct s_helm_sort_sub
{
	int max;
	int min;
	int place;
};

struct s_helm_sort
{
	int			quatre;
	int			pushed;
	int			reverse;
	
	// Mode forward and mode reverse
	t_hss		mr;
	t_hss		mf;
	
	int			rotations;

	t_sort		*sort;
	t_median	*med;
};

void	ext_op_rbn(t_sort *sort, int rotations)
{
	while (rotations != 0)
	{
		if (rotations < 0)
			op_rrb(sort);
		else
			op_rb(sort);
		rotations += ((rotations < 0) - (rotations > 0));
	}
}

void	push_back(t_sort *sort)
{
	int	rotations;
	int alt_rot;
	int max1;
	int max2;

	while (sort->b->count > 0)
	{
		max1 = stat_largest(sort->b, INT_MAX);	
		max2 = stat_largest(sort->b, max1 - 1);
		rotations = rotate_target(sort->b, sort->b->head, max1, 1);
		alt_rot = rotate_target(sort->b, sort->b->head, max2, 1);
		if (alt_rot * rotations > 0 && alt_rot < rotations)
		{
			ext_op_rbn(sort, alt_rot);
			op_pa(sort);
			rotations = rotate_target(sort->b, sort->b->head, max1, 1);
			ext_op_rbn(sort, rotations);	
			op_pa(sort);
			op_sa(sort);
			continue;
		}
		ext_op_rbn(sort, rotations);
		op_pa(sort);
	}
}



#include <unistd.h> // BAD INCLUDE
#include <stdio.h> // BAD

void helm_sort_reverse(t_hs *hs_ptr)
{
	t_hs hs;
	int max;
	int min;

	hs = *hs_ptr;
	hs.mr.min = get_largest(hs.med, hs.mr.place);
	max = hs.mr.max;
	min = hs.mr.min;
	printf("PUSHING: %d to %d\n", hs.mr.min, hs.mr.max);
	while (hs.rotations < hs.sort->a->count && hs.sort->a->count > 0)
	{
		if (hs.sort->a->head->value <= max && hs.sort->a->head->value >= min)
		{
			op_pb(hs.sort);
			hs.pushed++;
		}
		else
		{
			op_rra(hs.sort);
			hs.rotations++; // DO WE NEED THIS ANYMORE?
		}
	}
	hs.mr.max = get_largest(hs.med, hs.mr.place + 1);
	push_back(hs.sort);
	hs.mr.place += hs.pushed;
	printf("align!!\n");
	while (hs.pushed != 0)
	{
		op_ra(hs.sort);
		hs.pushed--;
	}
	*hs_ptr = hs; 
}

void helm_sort_forward(t_hs *hs_ptr)
{
	t_hs hs;
	int min;
	int max;

	hs = *hs_ptr;
	hs.mf.max = get_smallest(hs.med, hs.mf.place);
	min = hs.mf.min;
	max = hs.mf.max;
	printf("PUSHING: %d to %d\n", hs.mf.min, hs.mf.max);
	while (hs.rotations < hs.sort->a->count && hs.sort->a->count > 0)
	{
		if (hs.sort->a->head->value <= max && hs.sort->a->head->value >= min)
		{
			op_pb(hs.sort);
			hs.pushed++;  // Do we need this for forward?
		}
		else
		{
			op_ra(hs.sort);
			hs.rotations++; // Do we need this?
		}
	}
	hs.mf.min = get_smallest(hs.med, hs.mf.place + 1);
	push_back(hs.sort);
	hs.mf.place += hs.pushed;
	*hs_ptr = hs; 
}

/* Helm sort:
 * Sort stack 'A' using the following approach:
 * Let 'n' be the amount of elements in the stack
 * Let 'b' be the bucket size.
 * Move the 'n/b' largest integers into 'B'
 * The move from stack 'B' move the largest back into 'A'
 */
void	helm_sort(t_sort *sort, int cut)
{
	const int	quatre = (sort->a->count / cut) + (sort->a->count < cut);
	t_hs		hs;

	hs.sort = sort;
	hs.mr.place = quatre;
	hs.mf.place = quatre;
	hs.med = create_median(sort->a);
	hs.mf.min = INT_MIN;
	hs.mr.max = INT_MAX;
	hs.reverse = 0;
	while (!is_sorted(sort))
	{
		hs.rotations = 0;
		hs.pushed = 0;
		if (!hs.reverse)
			helm_sort_forward(&hs);
		else
			helm_sort_reverse(&hs);
		hs.reverse = !hs.reverse;
	}
	if (is_sorted(sort))
		printf("Successfull sorted\n\n!");
	med_delete(&hs.med);
}
