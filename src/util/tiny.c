/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42adel.org.au>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:05:46 by clovell           #+#    #+#             */
/*   Updated: 2023/07/20 17:52:42 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "sort.h"

// *
// **
// ***
//
// **
// *
// ***
//
// ***
// **
// *
//
// ***
// *
// **
//
// **
// ***
// *
//
// 123 x x x 
// 132 x x x
// 213 x x x
// 231 x x x
// 312 x x x
// 321 x x x

// *
// ***
// **
// 132

/* Return true if some place n is equal to some index, x,'s value. */
static int	eval(t_sort *sort, int n, int x, t_median *med)
{
	if (n == 1)
		return (sort->a->head->value == get_smallest(med, x - 1));
	else if (n == 2)
		return (sort->a->head->next->value == get_smallest(med, x - 1));
	else if (n == 3)
		return (sort->a->head->next->next->value == get_smallest(med, x - 1));
	return (0);
}

/* Sorts stack A in less than or equal to three operations.
 * When there is 3 or less elements.
 */
void	tiny_sort(t_sort *sort)
{
	t_median	*med;

	if (sort->a->count > 4 || sort->a->count < 3)
		return ;
	med = create_median(sort->a);
	if (eval(sort, 1, 3, med) && eval(sort, 3, 2, med))
		op_ra(sort);
	if (eval(sort, 1, 1, med) && eval(sort, 3, 2, med))
		op_rra(sort);
	if (eval(sort, 1, 2, med) && eval(sort, 3, 1, med))
		op_rra(sort);
	if (eval(sort, 1, 2, med) && eval(sort, 3, 3, med))
		op_sa(sort);
	else if (eval(sort, 1, 3, med) && eval(sort, 3, 1, med))
	{
		op_sa(sort);
		op_rra(sort);
	}
	med_delete(&med);
}
