/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:19:55 by clovell           #+#    #+#             */
/*   Updated: 2023/05/23 13:48:44 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "stack.h"

typedef struct s_sort	t_sort;

struct s_sort
{
	t_stack	*a;
	t_stack	*b;
};

void	write_op(char *op);

void	st_rev_rotate(t_stack *s);
void	op_rra(t_sort *sort);
void	op_rrb(t_sort *sort);
void	op_rrr(t_sort *sort);

void	st_rotate(t_stack *s);
void	op_ra(t_sort *sort);
void	op_rb(t_sort *sort);
void	op_rr(t_sort *sort);

void	st_swap(t_stack	*s);
void	op_sa(t_sort *sort);
void	op_sb(t_sort *sort);
void	op_ss(t_sort *sort);

void	op_pa(t_sort *sort);
void	op_pb(t_sort *sort);
#endif
