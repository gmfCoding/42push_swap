/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:12:35 by clovell           #+#    #+#             */
/*   Updated: 2023/05/23 13:40:39 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"
#include "sort.h"

void	stn_print(t_sort *sort)
{
	t_node	*a;
	t_node	*b;

	a = sort->a->head;
	b = sort->b->head;
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d", a->value);
			a = a->next;
		}
		if (b)
		{
			ft_printf("\t%d", b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("-------\n");
	ft_printf("A\tB\n");
}

int	main(int argc, char **argv)
{
	t_sort	sort;
	t_node	*next;
	t_node	*prev;
	int		i;

	sort.a = st_new("a");
	sort.b = st_new("b");
	sort.a->head = stn_new(ft_atoi(argv[1]));
	next = sort.a->head;
	i = 2;
	while (i < argc)
	{
		next->next = stn_new(ft_atoi(argv[i]));
		prev = next;
		next = next->next;
		next->prev = prev;
		i++;
	}
	sort.a->tail = next;
	stn_print(&sort);
}
