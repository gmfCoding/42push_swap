/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:55:27 by clovell           #+#    #+#             */
/*   Updated: 2023/05/29 14:26:25 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "sort.h"

void	st_swap(t_stack	*s)
{
	int	first;
	int	second;

	if (!s->head || !s->head->next)
		return ;
	first = st_pop(s);
	second = st_pop(s);
	st_push(s, first);
	st_push(s, second);
}

int	op_sa(t_sort *sort)
{
	if (sort->a->count <= 0)
			return (0);
	write_op("sa");
	st_swap(sort->a);
	sort->op_counter++;
	return (1);
}

int	op_sb(t_sort *sort)
{
	if (sort->b->count <= 0)
			return (0);
	write_op("sb");
	st_swap(sort->b);
	sort->op_counter++;
	return (1);
}

int	op_ss(t_sort *sort)
{
	
	if (sort->a->count <= 0 || sort->b->count <= 0)
			return (0);
	write_op("ss");
	st_swap(sort->a);
	st_swap(sort->b);
	sort->op_counter++;
	return (1);
}
