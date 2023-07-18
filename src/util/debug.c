/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42adel.org.au>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:48:43 by clovell           #+#    #+#             */
/*   Updated: 2023/07/18 17:49:24 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"
#include "stack.h"
#include "ft_printf.h"

int	dbg_get_value_at(t_stack *st, int rotations)
{
	t_node	*value;

	value = st->head;
	while (rotations != 0)
	{
		if (rotations < 0)
			value = value->prev;
		else
			value = value->next;
		rotations += ((rotations < 0) - (rotations > 0));
	}
	return (value->value);
}

void	stn_print(t_sort *sort)
{
	t_node	*a;
	t_node	*b;

	a = sort->a->head;
	b = sort->b->head;
	ft_printf("---------\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d\t", a->value);
			a = a->next;
		}
		else
			ft_printf("\t");
		if (b)
		{
			ft_printf("%d", b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("---------\n");
	ft_printf("A\tB\n");
	ft_printf("in %d operations.\n", sort->op_counter);
}
