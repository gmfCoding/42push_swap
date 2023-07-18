/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:54:40 by clovell           #+#    #+#             */
/*   Updated: 2023/07/18 17:30:25 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "sort.h"

void	parse(t_sort *sort, int argc, char **argv)
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
			st_push(sort->a, ft_atoi(*itr));
			itr++;
		}
	}
	else
	{
		i = argc - 1;
		while (i > 0)
		{
			st_push(sort->a, ft_atoi(argv[i]));
			i--;
		}
	}
}
