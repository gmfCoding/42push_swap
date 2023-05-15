/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:34:36 by clovell           #+#    #+#             */
/*   Updated: 2023/04/06 19:01:13 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LPRINTF_H
# define FT_LPRINTF_H

int	ft_putchar_sfd(char c, int fd);
int	ft_putstr_sfd(const char *str, int fd);
int	ft_puthex_sfd(unsigned long long number, int capital, int h64, int fd);
int	ft_putnb_sfd(long long number, int negative, int i64, int fd);
#endif
