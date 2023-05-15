/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_sfd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:12:40 by clovell           #+#    #+#             */
/*   Updated: 2023/04/06 19:13:47 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	puthex_r(unsigned int number, char *hex, int fd)
{
	int	count;

	if (number == 0)
		return (0);
	count = puthex_r(number / 16, hex, fd);
	if (count < 0)
		return (-1);
	if (write(1, &hex[number % 16], fd) < 0)
		return (-1);
	return (count + 1);
}

static int	put64hex_r(unsigned long long number, char *hex, int fd)
{
	int	count;

	if (number == 0)
		return (0);
	count = put64hex_r(number / 16, hex, fd);
	if (count < 0)
		return (-1);
	if (write(1, &hex[number % 16], fd) < 0)
		return (-1);
	return (count + 1);
}

int	ft_puthex_sfd(unsigned long long number, int capital, int h64, int fd)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (capital)
		hex = "0123456789ABCDEF";
	if (number != 0)
	{
		if (h64)
			return (put64hex_r(number, hex, fd));
		else
			return (puthex_r(number, hex, fd));
	}
	if (write(1, "0", 1) < 0)
		return (-1);
	return (1);
}
