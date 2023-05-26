/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   least_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:17:08 by clovell           #+#    #+#             */
/*   Updated: 2023/05/26 15:23:00 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_range t_range;

struct s_range
{
	int min;
	int max;
};

t_range	find_range(t_stack *stack, int counted, int maxmin)
{
	t_node	*next;
	t_range	range;
	t_range range2;

	range.min = INT_MAX;
	next = stack->head;
	while (next)
	{
		if (maxmin < range.min && next->value < range.min)
			range.min = value;
		next = next->next;
	}
	next = stack->head;
	while (counted > 0)
	{
		while (next)
		{
			if (next->value > range.min && next->value < range.max)
			next = next->next;
		}
		counted--;
	}
}

void	least_sort(t_sort *sort)
{
		
}
