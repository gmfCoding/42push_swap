/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:44:06 by clovell           #+#    #+#             */
/*   Updated: 2023/05/23 12:49:10 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

void	op_pa(t_sort *sort)
{
	int	value;

	write_op("pa");
	value = st_pop(sort->b);
	st_push(sort->a, value);
}

void	op_pb(t_sort *sort)
{
	int	value;

	write_op("pb");
	value = st_pop(sort->a);
	st_push(sort->b, value);
}
