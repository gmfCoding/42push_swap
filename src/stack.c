/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:45:34 by clovell           #+#    #+#             */
/*   Updated: 2023/06/05 14:46:02 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "stack.h"

t_stack	*st_new(char *name)
{
	t_stack *stack;

	stack = ft_calloc(sizeof(t_stack), 1);
	stack->name = name;
	return (stack);
}

void	st_delete(t_stack *stack)
{
	t_node *next;
	t_node *tmp;
	next = stack->head;
	while (next)
	{
		tmp = next->next;
		free(next);
		next = tmp;
	}
	free(stack);
}

void	st_push(t_stack *stack, int value)
{
	t_node	*node;

	node = stn_new(value);
	if (stack->head)
	{
		node->next = stack->head;
		stack->head->prev = node;
	}
	stack->head = node;
	if (!stack->tail)
		stack->tail = node;
	stack->count++;
}

int	st_pop(t_stack *stack)
{
	t_node	*pop;
	int		value;

	pop = stack->head;
	if (pop->next)
		pop->next->prev = NULL;
	else
		stack->tail = NULL;
	stack->head = pop->next;
	value = pop->value;
	free(pop);
	stack->count--;
	return (value);
}
