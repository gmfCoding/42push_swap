/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:49:38 by clovell           #+#    #+#             */
/*   Updated: 2023/06/02 17:47:44 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "sort.h"



/* 1-2-3 == 2-3-1
 * H   T
 *  H
 * 
 */
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
	move->prev = *tail;
	move->next = NULL;
	(*tail) = move;
}

void	op_ra(t_sort *sort)
{
	if (!sort->a->head->next)
		return ;
	write_op("ra");
	st_rotate(sort->a);
	sort->op_counter++;
}

void	op_rb(t_sort *sort)
{
	if (!sort->b->head->next)
		return ;
	write_op("rb");
	st_rotate(sort->b);
	sort->op_counter++;
}

void	op_rr(t_sort *sort)
{
	if (!sort->a->head->next || !sort->b->head->next)
		return ;
	write_op("rr (ra, rb)");
	st_rotate(sort->a);
	st_rotate(sort->b);
	sort->op_counter++;
}
