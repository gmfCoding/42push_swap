/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:17:54 by clovell           #+#    #+#             */
/*   Updated: 2023/05/25 12:03:43 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;

struct s_stack
{
	char	*name;
	t_node	*head;
	t_node	*tail;
	int		count;
};

struct s_node
{
	t_node	*next;
	t_node	*prev;
	int		value;
};

int		st_ishead(t_node *node);
int		st_istail(t_node *node);
t_node	*stn_new(int value);
t_stack	*st_new(char *name);
void	st_push(t_stack *stack, int value);
int		st_pop(t_stack *stack);

void	st_delete(t_stack *stack);

#endif
