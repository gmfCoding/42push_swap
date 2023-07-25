/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:54:40 by clovell           #+#    #+#             */
/*   Updated: 2023/07/25 17:27:25 by clovell          ###   ########.fr       */
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

static int	handle_quoted(t_sort *sort, char *args)
{
	char	**nums;
	char	**itr;

	nums = ft_split(args, ' ');
	itr = nums;
	while (*itr)
	{
		if (push(sort, *itr))
			return (free_split(nums));
		itr++;
	}
	free_split(nums);
	return (0);
}

int	parse(t_sort *sort, int argc, char **argv)
{
	int		i;

	if (argc <= 1 || *argv[1] == '\0')
		return (0);
	if (ft_strchr(argv[1], ' ') != NULL)
	{
		if (argc >= 3)
			return (1);
		return (handle_quoted(sort, argv[1]));
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
