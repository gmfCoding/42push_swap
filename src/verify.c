/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:26:35 by clovell           #+#    #+#             */
/*   Updated: 2023/07/20 01:18:23 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

int	no_duplicates(t_sort *sort)
{
	t_median	*med;
	int			i;

	i = 0;
	med = create_median(sort->a);
	while (i < (med->size - 1))
	{
		if (med->array[i] == med->array[i + 1])
		{
			med_delete(&med);
			return (0);
		}
		i++;
	}
	med_delete(&med);
	return (1);
}

int	is_sorted(t_sort *sort)
{
	t_node	*curr;

	if (sort->b->count != 0)
		return (0);
	curr = sort->a->head;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}
