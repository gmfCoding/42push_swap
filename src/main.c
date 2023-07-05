/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:12:35 by clovell           #+#    #+#             */
/*   Updated: 2023/05/24 17:08:23 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

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
		else
			ft_printf("\t");
		if (b)
		{
			ft_printf("%d", b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("---------\n");
	ft_printf("A\tB\n");
	ft_printf("in %d operations.\n", sort->op_counter);
}

t_sort	*initialise(int argc, char **argv)
{
	t_sort	*sort;

	sort = ft_calloc(sizeof(t_sort), 1);
	sort->op_counter = 0;
	sort->a = st_new("a");
	sort->b = st_new("b");
	parse(sort, argc, argv);
	return (sort);
}
#include <stdio.h>
#include <unistd.h> // WARNING
int	main(int argc, char **argv)
{
	t_sort	*sort;
	setbuf(stdout, NULL); // WARNING
	sort = initialise(argc, argv);
	//helm_sort(sort);
	//decision_sort(sort);
	tiny_sort(sort);
	stn_print(sort);
	st_delete(sort->a);
	st_delete(sort->b);
	free(sort);
}
