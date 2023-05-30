/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:49:38 by clovell           #+#    #+#             */
/*   Updated: 2023/05/30 13:58:15 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "sort.h"

void	st_rotate(t_stack *s)
{
	t_node	*move;
	t_node	**head;
	t_node	**tail;
	
	head = &s->head;	
	tail = &s->tail;
	move = *head;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	(*tail)->next = move;
	(*tail) = move;
	move->prev = *tail;
	move->next = NULL;
}

void	op_ra(t_sort *sort)
{
	write_op("ra");
	st_rotate(sort->a);
	sort->op_counter++;
}

void	op_rb(t_sort *sort)
{
	write_op("rb");
	st_rotate(sort->b);
	sort->op_counter++;
}

void	op_rr(t_sort *sort)
{
	write_op("rr (ra, rb)");
	st_rotate(sort->a);
	st_rotate(sort->b);
	sort->op_counter++;
}
