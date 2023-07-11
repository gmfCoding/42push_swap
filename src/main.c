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
	t_sort		*sort;

	sort = ft_calloc(sizeof(t_sort), 1);
	sort->op_counter = 0;
	sort->a = st_new("a");
	sort->b = st_new("b");
	parse(sort, argc, argv);
	sort->med = create_median(sort->a);
	sort->min = get_smallest(sort->med, 0);
	sort->max = get_largest(sort->med, 0);
	return (sort);
}

int	main(int argc, char **argv)
{
	static int	cut = 1;
	t_sort		*sort;
	
	sort = initialise(argc, argv);
	if (sort->a->count > 40)
		cut = 2;
	if (sort->a->count > 70)
		cut = 4;
	if (sort->a->count > 250)
		cut = 8;
	if (sort->a->count > 600)
		cut = sort->a->count / 60;
	helm_sort(sort, cut);
	if (is_sorted(sort))
		ft_printf("Successfull sorted in %d\n\n!", sort->op_counter); // REMOVE
	med_delete(&sort->med);
	st_delete(sort->a);
	st_delete(sort->b);
	free(sort);
}
