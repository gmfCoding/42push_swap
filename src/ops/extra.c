/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42adel.org.au>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:02:58 by clovell           #+#    #+#             */
/*   Updated: 2023/07/18 18:03:02 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

void	ext_op_xn(t_sort *sort, t_opfunc op, t_opfunc rev, int amount)
{
	while (amount != 0)
	{
		if (amount < 0)
			rev(sort);
		else
			op(sort);
		amount += ((amount < 0) - (amount > 0));
	}
}
