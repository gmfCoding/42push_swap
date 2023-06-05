/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:49:24 by clovell           #+#    #+#             */
/*   Updated: 2023/06/05 14:44:10 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "sort.h"

void	st_rev_rotate(t_stack *s)
{
	t_node	*move;
	t_node	**head;
	t_node	**tail;

	head = &s->head;	
	tail = &s->tail;
	move = *tail;
	(*tail) = (*tail)->prev;
	(*tail)->next = NULL;
	(*head)->prev = move;
	move->prev = NULL;
	move->next = *head;
	(*head) = move;
}

int	op_rra(t_sort *sort)
{
	if (sort->a->count <= 1)
		return (0);
	write_op("rra");
	st_rev_rotate(sort->a);
	sort->op_counter++;
	return (1);
}

int	op_rrb(t_sort *sort)
{
	if (sort->b->count <= 1)
		return (0);
	write_op("rrb");
	st_rev_rotate(sort->b);
	sort->op_counter++;
	return (1);
}

int	op_rrr(t_sort *sort)
{
	if (sort->a->count <= 1 || sort->b->count <= 1)
		return (0);
	write_op("rrr");
	st_rev_rotate(sort->a);
	st_rev_rotate(sort->b);
	sort->op_counter++;
	return (1);
}
