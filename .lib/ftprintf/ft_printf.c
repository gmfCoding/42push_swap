/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:01:44 by clovell           #+#    #+#             */
/*   Updated: 2023/04/06 19:35:24 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>

#include "ft_lprintf.h"

static int	process_advanced(char fmt, va_list values)
{
	int	accum;

	accum = 0;
	if (fmt == 'p')
	{	
		accum = ft_putstr_sfd("0x", 1);
		if (accum < 0)
			return (-1);
		accum += ft_puthex_sfd(va_arg(values, unsigned long long), 0, 1, 1);
		if ((accum - 2) < 0)
			return (-1);
	}
	else if (fmt == 'x')
		accum = ft_puthex_sfd(va_arg(values, int), 0, 0, 1);
	else if (fmt == 'X')
		accum = ft_puthex_sfd(va_arg(values, int), 1, 0, 1);
	else if (fmt == 'd' || fmt == 'i')
		accum = ft_putnb_sfd(va_arg(values, int), 1, 0, 1);
	else if (fmt == 'u')
		accum = ft_putnb_sfd(va_arg(values, unsigned int), 0, 1, 1);
	if (accum < 0)
		return (-1);
	return (accum);
}

static int	process_value(char fmt, va_list values, int *count)
{
	int	accum;

	accum = 0;
	if (fmt == '%')
		accum = ft_putchar_sfd('%', 1);
	else if (fmt == 'c')
		accum = ft_putchar_sfd(va_arg(values, int), 1);
	else if (fmt == 's')
		accum = ft_putstr_sfd(va_arg(values, char *), 1);
	else
		accum = process_advanced(fmt, values);
	va_end(values);
	if (fmt != 's' && accum <= 0)
		return (-1);
	if (accum > 0)
		*count += accum;
	return (accum);
}

int	ft_vprintf(const char *fmt, va_list values)
{
	int	printed;
	int	temp;

	printed = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (process_value(*(fmt + 1), values, &printed) < 0)
				return (-1);
			fmt++;
		}
		else
		{
			temp = ft_putchar_sfd(*fmt, 1);
			if (temp < 0)
				return (-1);
			printed += temp;
		}
		fmt++;
	}
	return (printed);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	values;

	va_start(values, fmt);
	return (ft_vprintf(fmt, values));
}
