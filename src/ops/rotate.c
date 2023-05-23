/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:49:38 by clovell           #+#    #+#             */
/*   Updated: 2023/05/23 12:49:41 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "sort.h"

void	st_rotate(t_stack *s)
{
	t_node	*node;

	node = s->head;
	s->head = s->head->next;
	s->tail->next = node;
	s->tail = node;
	if (!s->head)
		s->head = s->tail;
}

void	op_ra(t_sort *sort)
{
	write_op("ra");
	st_rotate(sort->a);
}

void	op_rb(t_sort *sort)
{
	write_op("rb");
	st_rotate(sort->b);
}

void	op_rr(t_sort *sort)
{
	write_op("rr (ra, rb)");
	st_rotate(sort->a);
	st_rotate(sort->b);
}
