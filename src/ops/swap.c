/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:55:27 by clovell           #+#    #+#             */
/*   Updated: 2023/05/23 12:49:51 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "sort.h"

void	st_swap(t_stack	*s)
{
	int	first;
	int	second;

	first = st_pop(s);
	second = st_pop(s);
	st_push(s, first);
	st_push(s, second);
}

void	op_sa(t_sort *sort)
{
	write_op("sa");
	st_swap(sort->a);
}

void	op_sb(t_sort *sort)
{
	write_op("sb");
	st_swap(sort->b);
}

void	op_ss(t_sort *sort)
{
	write_op("ss (sa, sb)");
	st_swap(sort->a);
	st_swap(sort->b);
}
