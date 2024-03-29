/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:10:57 by clovell           #+#    #+#             */
/*   Updated: 2023/07/19 23:22:45 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MEDIAN_H
# define MEDIAN_H
# include "stack.h"

typedef struct s_median
{
	int	*array;
	int	size;
	int	median;
	int	num1;
	int	num2;
	int	answer;
}	t_median;

int			med_first_value_lte(t_median *med, int curr);
int			med_idx_fit_value(t_median *med, int value);
int			median_prev(t_median *med, int curr);
int			median_next(t_median *med, int curr);

int			get_largest(t_median *median, int kth);
int			get_smallest(t_median *median, int kth);
t_median	*create_median(t_stack *stack);

int			median(t_median *median);
t_median	*median_from_stack(t_stack *stack);
void		med_delete(t_median **median);
#endif
