/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:37:15 by clovell           #+#    #+#             */
/*   Updated: 2023/07/12 16:39:17 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

int	st_ishead(t_node *node)
{

	// REMOVE IF UNUSED
	return (node->prev == NULL);
}

int	st_istail(t_node *node)
{
	// REMOVEI IF UNUSED
	return (node->next == NULL);
}

t_node	*stn_new(int value)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	node->value = value;
	return (node);
}
