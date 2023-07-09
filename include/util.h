/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:44:49 by clovell           #+#    #+#             */
/*   Updated: 2023/06/06 15:44:52 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int    stat_largest(t_stack *stack, int max);
int    stat_smallest(t_stack *stack, int min);

int rotate_target(t_stack *stack, t_node *next, int target, int forwards);
int rotate_smallest(t_stack *stack, t_node *next, int forwards);
int rotate_largest(t_stack *stack, t_node *next, int forwards);

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
