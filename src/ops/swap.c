/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:55:27 by clovell           #+#    #+#             */
/*   Updated: 2023/05/24 16:59:02 by clovell          ###   ########.fr       */
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

void	op_sa(t_sort *sort)
{
	write_op("sa");
	st_swap(sort->a);
	sort->op_counter++;
}

void	op_sb(t_sort *sort)
{
	write_op("sb");
	st_swap(sort->b);
	sort->op_counter++;
}

void	op_ss(t_sort *sort)
{
	write_op("ss (sa, sb)");
	st_swap(sort->a);
	st_swap(sort->b);
	sort->op_counter++;
}
