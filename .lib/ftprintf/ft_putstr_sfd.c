/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_sfd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:28:07 by clovell           #+#    #+#             */
/*   Updated: 2023/04/06 19:03:29 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_putstr_sfd(const char *str, int fd)
{
	int	len;

	if (!str)
		return (ft_putstr_sfd("(null)", fd));
	len = 0;
	while (str[len])
	{
		if (write(fd, &str[len], 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}
