/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:10:57 by clovell           #+#    #+#             */
/*   Updated: 2023/05/29 18:04:34 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIVOT_H
# define PIVOT_H
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

int	get_smallest(t_median *median, int kth);
t_median *create_median(t_stack *stack);

int			median(t_median *median);
t_median	*median_from_stack(t_stack *stack);
void		med_delete(t_median **median);
#endif
