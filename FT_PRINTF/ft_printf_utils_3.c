/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:01:56 by bleaf             #+#    #+#             */
/*   Updated: 2022/01/12 03:54:08 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_unb_len(unsigned int nb, int del)
{
	long int	i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb)
	{
		i++;
		nb /= del;
	}
	return (i);
}

int	ft_get_ul_len(unsigned long nb)
{
	long unsigned	i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

unsigned int	ft_pow(int num, int pow)
{
	unsigned int	ans;

	ans = (unsigned int) num;
	if (pow == 0)
		return (1);
	while (pow--)
		ans *= num;
	return (ans);
}

unsigned long	ft_ulpow(int num, int pow)
{
	unsigned long	ans;

	ans = (unsigned long) num;
	if (!pow)
		return (1);
	while (pow--)
		ans *= num;
	return (ans);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
