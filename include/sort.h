/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:19:55 by clovell           #+#    #+#             */
/*   Updated: 2023/06/12 17:37:49 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "stack.h"

typedef struct s_sort	t_sort;

typedef void			(*t_opfunc)(t_sort *sort);

struct s_sort
{
	t_stack	*a;
	t_stack	*b;
	int		op_counter;
};

int		is_sorted(t_sort *sort);

void	bubble_sort(t_sort *sort);
void	helm_sort(t_sort *sort, int cut);

void	write_op(char *op);

void	st_rev_rotate(t_stack *s);
int		op_rra(t_sort *sort);
int		op_rrb(t_sort *sort);
int		op_rrr(t_sort *sort);

void	st_rotate(t_stack *s);
int		op_ra(t_sort *sort);
int		op_rb(t_sort *sort);
int		op_rr(t_sort *sort);

void	st_swap(t_stack	*s);
int		op_sa(t_sort *sort);
int		op_sb(t_sort *sort);
int		op_ss(t_sort *sort);

int		op_pa(t_sort *sort);
int		op_pb(t_sort *sort);
#endif
