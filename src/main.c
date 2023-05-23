/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:12:35 by clovell           #+#    #+#             */
/*   Updated: 2023/05/23 22:05:24 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"
#include "sort.h"
#include "program.h"

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

t_sort	*initialise(int argc, char **argv)
{
	t_sort	*sort;

	sort = ft_calloc(sizeof(t_sort), 1);
	sort->a = st_new("a");
	sort->b = st_new("b");
	parse(sort, argc, argv);
	return (sort);
}

int	main(int argc, char **argv)
{
	t_sort	*sort;

	sort = initialise(argc, argv);

	op_pb(sort);
	op_ra(sort);
	op_pb(sort);
	op_rb(sort);
	op_sa(sort);
	stn_print(sort);
}
