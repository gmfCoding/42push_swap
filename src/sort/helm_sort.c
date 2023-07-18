/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helm_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:24:28 by clovell           #+#    #+#             */
/*   Updated: 2023/07/18 18:13:47 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "sort.h"
#include "stack.h"
#include "median.h"
#include "util.h"
#include "debug.h" //REMOVE
#include "ft_printf.h"

typedef struct s_helm_sort		t_hs;
typedef struct s_helm_sort_mode	t_hm;
typedef long long int			t_i64;

struct s_helm_sort_mode
{
	t_i64	place;
	t_i64	max;
	t_i64	min;
};

struct s_helm_sort
{
	int			quatre;
	int			pushed;
	int			reverse;

	t_hm		mf;
	t_hm		mr;

	t_i64		p_max;
	int			rotations;
	t_sort		*sort;
};

/* Pushes from B to A (in a smart way)
 * 
 *
 *
 *
 */
void	push_back(t_sort *sort)
{
	int	rotations;
	int	alt_rot;
	int	max1;
	int	max2;

	while (sort->b->count > 0)
	{
		max1 = stat_largest(sort->b, INT_MAX);
		max2 = stat_largest(sort->b, max1 - 1);
		rotations = rotate_target(sort->b, sort->b->head, max1, 1);
		alt_rot = rotate_target(sort->b, sort->b->head, max2, 1);
		if (alt_rot * rotations > 0 && alt_rot < rotations)
		{
			ext_op_xn(sort, op_rb, op_rrb, alt_rot);
			op_pa(sort);
			rotations = rotate_target(sort->b, sort->b->head, max1, 1);
			ext_op_xn(sort, op_rb, op_rrb, rotations);
			op_pa(sort);
			op_sa(sort);
			continue ;
		}
		ext_op_xn(sort, op_rb, op_rrb, rotations);
		op_pa(sort);
	}
}

/* Pushes values from A into B.
 * rotate through the unordered region of A if you come across
 * a value that is within the range stored in helm_mode struct
 * then it's pushed into b.
 * the rest of the logic is handling the stoping of the pushing
 * such as when we reach then end of the range.
 * 
 * Improvement Idea:
 * Use a proper median for semi-sort into a instead of:
 * value < (min + (max - min) / 2)
 */
void	push_to_b(t_hs *hs, t_hm m, t_opfunc rot, int rev)
{
	t_stack	*a;

	a = hs->sort->a;
	while (hs->rotations < a->count + hs->pushed && a->count > 0)
	{
		if (rev)
			if (a->head->value == hs->sort->min || a->head->value > m.max)
				break ;
		if (a->head->value <= m.max && a->head->value >= m.min)
		{
			op_pb(hs->sort);
			if (hs->sort->b->head->value > m.min + ((m.max - m.min) / 2))
				op_rb(hs->sort);
			hs->pushed++;
		}
		else
		{
			if (!rev && a->tail->value == hs->p_max)
				break ;
			rot(hs->sort);
			hs->rotations++;
		}
	}
}

void	helm_sort_mode(t_hs *hs, t_hm *hm, int rev)
{
	int			(*med)(t_median*, int);
	t_opfunc	op;
	t_i64		*v2;
	t_i64		*v1;

	hs->rotations = 0;
	hs->pushed = 0;
	med = &get_smallest;
	v1 = &hm->max;
	v2 = &hm->min;
	op = op_rra;
	if (rev)
	{
		med = &get_largest;
		v1 = &hm->min;
		v2 = &hm->max;
		op = op_ra;
	}
	*v1 = med(hs->sort->med, hm->place);
	push_to_b(hs, *hm, op, rev);
	*v2 = med(hs->sort->med, hm->place + 1);
	push_back(hs->sort);
	hm->place += hs->pushed;
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
	t_hs		hs;
	int			final_rot;

	hs.sort = sort;
	hs.mr.place = (sort->a->count / cut) + (sort->a->count < cut);
	hs.mf.place = hs.mr.place;
	hs.mf.min = get_smallest(sort->med, 0) - 1;
	hs.mr.max = get_largest(sort->med, 0) + 1;
	hs.reverse = 0;
	hs.p_max = INT_MAX;
	while (cut > 0)
	{
		if (!hs.reverse)
			helm_sort_mode(&hs, &hs.mf, 0);
		else
			helm_sort_mode(&hs, &hs.mr, 1);
		if (!hs.reverse)
			ext_op_xn(sort, op_ra, (void *)0, hs.pushed);
		hs.p_max = hs.mf.max;
		hs.reverse = !hs.reverse;
		cut--;
	}
	final_rot = rotate_target(sort->a, sort->a->head, sort->min, 1);
	ext_op_xn(hs.sort, op_ra, op_rra, final_rot);
}
