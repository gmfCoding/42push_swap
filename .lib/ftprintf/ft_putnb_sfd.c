/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_sfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:04:04 by clovell           #+#    #+#             */
/*   Updated: 2023/04/06 19:12:08 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_lprintf.h"
#include <unistd.h>

static int	putlnb_r(unsigned long long number, int fd)
{
	int		count;
	char	c;

	if (number == 0)
		return (0);
	count = putlnb_r(number / 10, fd);
	if (count < 0)
		return (-1);
	c = (number % 10) + '0';
	if (write(1, &c, fd) < 0)
		return (-1);
	return (count + 1);
}

static int	putnb_r(unsigned int number, int fd)
{
	int		count;
	char	c;

	if (number == 0)
		return (0);
	count = putnb_r(number / 10, fd);
	if (count < 0)
		return (-1);
	c = (number % 10) + '0';
	if (write(1, &c, fd) < 0)
		return (-1);
	return (count + 1);
}

int	ft_putnb_sfd(long long number, int negative, int i64, int fd)
{
	unsigned long long	nb;

	nb = number;
	if (negative && number < 0)
	{
		if (ft_putchar_sfd('-', fd) < 0)
			return (-1);
		nb = -number;
	}
	if (nb != 0)
	{
		if (i64)
			return ((number < 0) + putlnb_r(nb, fd));
		else
			return ((number < 0) + putnb_r(nb, fd));
	}
	if (ft_putchar_sfd('0', fd) < 0)
		return (-1);
	return (1);
}
