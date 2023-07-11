/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:19:55 by clovell           #+#    #+#             */
/*   Updated: 2023/05/29 16:59:58 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "stack.h"
# include "pivot.h"

typedef struct s_sort	t_sort;

typedef int			(*t_opfunc)(t_sort *sort);

struct s_sort
{
	t_stack	*a;
	t_stack	*b;
	int		op_counter;

	int			min;
	int			max;
	int			count;
	t_median	*med;
};


void	bubble_sort(t_sort *sort);

void	helm_sort(t_sort *sort, int cut);

/* Returns 1 if stack A is in a fully sorted state */
int		is_sorted(t_sort *sort);

/* Returns the largest value inside a stack that is less than or equal to max */
int		stat_largest(t_stack *stack, int max);
/* Returns the smallest value inside a stack that is greather than or equal to min */
int		stat_smallest(t_stack *stack, int min);

/* Returns the minimum amount of rotations needed to get some value to the top of the stack.
 * Always next: stack->head for public calls.
 * Always forwards: 1 for public calls. 
 */
int		rotate_target(t_stack *stack, t_node *next, int target, int forwards);
int		rotate_smallest(t_stack *stack, t_node *next, int forwards);
int		rotate_largest(t_stack *stack, t_node *next, int forwards);

// Writes a specifc operation to the terminal
void	write_op(char *op);

/* Extra operations */
/* ext_op_xn:
 * Operation X n times, applies an operation 'op' and 'rev' 'amount' times.
 * When amount is greater than 0 it applies 'op' amount times.
 * When amount is less    than 0 it applies 'rev' amount times.
 * */
void	ext_op_xn(t_sort *sort, t_opfunc op, t_opfunc rev, int amount);

/* Main built-in operations */
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
