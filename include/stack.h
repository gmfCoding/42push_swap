/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:17:54 by clovell           #+#    #+#             */
/*   Updated: 2023/05/17 22:22:23 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef t_struct s_struct;

typedef t_stnode s_stnode;

struct s_stack
{
	t_stnode	*head;
	t_stnode	*tail;
	int			count;
};

struct s_stnode
{
	t_stnode	*next;
	t_stnode	*prev;
	int			value;
};

int	st_ishead(t_stnode node);
int	st_istail(t_stnode node);

#endif
