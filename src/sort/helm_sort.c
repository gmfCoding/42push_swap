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
		usleep(20000); // BAD FUNCTION, DO NOT USE.
	}
	//printf("Done\n\n!");
	if (is_sorted(sort))
		printf("Successfull sorted\n\n!");
	med_delete(&med);
}
