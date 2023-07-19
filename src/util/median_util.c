/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42adel.org.au>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:36:37 by clovell           #+#    #+#             */
/*   Updated: 2023/07/19 23:57:34 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "median.h"

/* Returns the last index that is less than or equal to value.
 * Such that the next index is greater than value.
 * */
int	med_idx_fit_value(t_median *med, int value)
{
	int	i;

	i = 0;
	while (i < (med->size - 1))
	{
		if (med->array[i] >= value && med->array[i + 1] > value)
			return (i);
		i++;
	}
	if (med->array[i] > value)
		return (i);
	return (0);
}

/* Returns the value less than curr,
 * if curr is the smallest value already it will return curr.
 */
int	med_first_value_lte(t_median *med, int curr)
{
	int	index;

	index = med_idx_fit_value(med, curr);
	return (med->array[index]);
}

/* Returns the value less than curr,
 * if curr is the smallest value already it will return curr.
 */
int	median_prev(t_median *med, int curr)
{
	int	index;

	index = med_idx_fit_value(med, curr);
	if (index == 0)
		index = 1;
	return (med->array[index - 1]);
}

/* Returns the next value greater than curr,
 * if curr is the largest value already it will return curr.
 */
int	median_next(t_median *med, int curr)
{
	int	index;

	index = med_idx_fit_value(med, curr);
	if (index >= med->size)
		index--;
	return (med->array[index + 1]);
}
