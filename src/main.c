/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:12:35 by clovell           #+#    #+#             */
/*   Updated: 2023/05/23 14:31:44 by clovell          ###   ########.fr       */
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
	ft_printf("---------\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d\t", a->value);
			a = a->next;
		}
		if (b)
		{
			ft_printf("%d", b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("---------\n");
	ft_printf("A\tB\n");
}

int	main(int argc, char **argv)
{
	t_sort	sort;
	int		i;

	sort.a = st_new("a");
	sort.b = st_new("b");
	i = argc - 1;
	while (i > 0)
	{
		st_push(sort.a, ft_atoi(argv[i]));
		i--;
	}
	op_pb(&sort);
	op_ra(&sort);
	op_pb(&sort);
	op_rb(&sort);
	op_sa(&sort);
	stn_print(&sort);
}
