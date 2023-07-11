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
#include "debug.h" // remove
				   
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
	static int cut = 1;
	t_sort	*sort;
	setbuf(stdout, NULL); // WARNING
	sort = initialise(argc, argv);
	if (sort->a->count > 40)
		cut = 2;
	if (sort->a->count > 70)
		cut = 4;
	if (sort->a->count > 250)
		cut = 8;
	helm_sort(sort, cut);
	stn_print(sort);
	st_delete(sort->a);
	st_delete(sort->b);
	free(sort);
}
