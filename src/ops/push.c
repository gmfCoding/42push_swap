/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:44:06 by clovell           #+#    #+#             */
/*   Updated: 2023/07/18 18:02:26 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

int	op_pa(t_sort *sort)
{
	int	value;

	if (sort->b->count == 0)
		return (0);
	write_op("pa");
	value = st_pop(sort->b);
	st_push(sort->a, value);
	sort->op_counter++;
	return (1);
}

int	op_pb(t_sort *sort)
{
	int	value;

	if (sort->a->count == 0)
		return (0);
	write_op("pb");
	value = st_pop(sort->a);
	st_push(sort->b, value);
	sort->op_counter++;
	return (1);
}
