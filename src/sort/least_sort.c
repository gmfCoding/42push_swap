/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   least_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:17:08 by clovell           #+#    #+#             */
/*   Updated: 2023/07/20 00:04:58 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "sort.h"

void	least_sort(t_sort *sort)
{
	t_median	*temp;
	int			i;
	int			rot;

	if (sort->a->count == 1)
		return ;
	else if (sort->a->count == 2)
	{
		if (sort->a->head->value > sort->a->head->next->value)
			op_ra(sort);
		return ;
	}
	ext_op_xn(sort, op_pb, NULL, sort->a->count - 3);
	tiny_sort(sort);
	while (sort->b->count > 0)
	{
		temp = create_median(sort->a);
		i = med_first_value_lte(temp, sort->b->head->value);
		rot = rotate_target(sort->a, sort->a->head, i, 1);
		ext_op_xn(sort, op_ra, op_rra, rot);
		op_pa(sort);
		med_delete(&temp);
	}
	rot = rotate_smallest(sort->a, sort->a->head, 1);
	ext_op_xn(sort, op_ra, op_rra, rot);
}
