/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:12:35 by clovell           #+#    #+#             */
/*   Updated: 2023/07/25 17:20:43 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "sort.h"
#include "program.h"

t_sort	*initialise(int argc, char **argv)
{
	t_sort	*sort;
	int		errored;

	sort = ft_calloc(sizeof(t_sort), 1);
	sort->op_counter = 0;
	sort->a = st_new("a");
	sort->b = st_new("b");
	errored = parse(sort, argc, argv);
	errored |= !no_duplicates(sort);
	if (errored)
		write(2, "Error\n", 6);
	if (errored || sort->a->count == 0 || is_sorted(sort))
	{
		st_delete(sort->a);
		st_delete(sort->b);
		free(sort);
		return (NULL);
	}
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
	if (sort != NULL)
	{
		if (sort->a->count > 40)
			cut = 2;
		if (sort->a->count > 70)
			cut = 4;
		if (sort->a->count > 250)
			cut = 8;
		if (sort->a->count > 600)
			cut = sort->a->count / 60;
		if (sort->a->count <= 5)
			least_sort(sort);
		else
			helm_sort(sort, cut);
		med_delete(&sort->med);
		st_delete(sort->a);
		st_delete(sort->b);
		free(sort);
	}
}
