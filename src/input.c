/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:54:40 by clovell           #+#    #+#             */
/*   Updated: 2023/07/20 01:19:41 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "sort.h"
#include <limits.h>
#include <stdlib.h>

static int	push(t_sort *sort, char *str)
{
	long long int	val;

	if (!ft_atol(str, &val) || val > INT_MAX || val < INT_MIN)
		return (1);
	st_push(sort->a, (int)val);
	if (sort->a->count > 1)
		st_rotate(sort->a);
	return (0);
}

static int	free_split(char **data)
{
	char	**temp;

	temp = data;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(data);
	return (1);
}

int	parse(t_sort *sort, int argc, char **argv)
{
	char	**nums;
	char	**itr;
	int		i;

	if (ft_strchr(argv[1], ' ') != NULL)
	{
		nums = ft_split(argv[1], ' ');
		itr = nums;
		while (*itr)
		{
			if (push(sort, *itr))
				return (free_split(nums));
			itr++;
		}
	}
	else
	{
		i = 1;
		while (i < argc)
			if (push(sort, argv[i++]))
				return (1);
	}
	return (0);
}
