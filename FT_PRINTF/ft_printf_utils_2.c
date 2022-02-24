/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:12:29 by bleaf             #+#    #+#             */
/*   Updated: 2022/01/12 04:23:16 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_put_unsign(unsigned int ui)
{
	int		len;
	int		i;
	char	*s;

	if (ui == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = ft_get_unb_len(ui, 10);
	i = len;
	s = (char *)malloc(sizeof(char) * len + 1);
	s[len] = '\0';
	if (!s)
		return (0);
	while (len--)
	{
		s[len] = ui % 10 + '0';
		ui /= 10;
	}
	write(1, s, i);
	free(s);
	return (i);
}

int	ft_put_pointer(unsigned long ul)
{
	char	*hex;
	int		i;
	int		j;
	char	*str;

	i = ft_get_ul_len(ul);
	j = i;
	str = "0123456789abcdef";
	write(1, "0x", 2);
	if (!ul)
		return (write(1, "0", 1) + 2);
	hex = (char *)malloc (sizeof(char) * i + 1);
	if (!hex)
		return (0);
	hex[i] = '\0';
	while (j--)
	{
		hex[j] = str[ul % 16];
		ul /= 16;
	}
	write(1, hex, i);
	free(hex);
	return (i + 2);
}

int	ft_put_hex(unsigned int dec, int flag)
{
	char	*str;
	char	*hex;
	int		i;
	int		j;

	if (dec == 0)
		return (write(1, "0", 1));
	i = ft_get_unb_len(dec, 16);
	j = i;
	hex = (char *)malloc (sizeof(char) * i + 1);
	if (!hex)
		return (0);
	hex[i] = '\0';
	if (flag)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	while (j--)
	{
		hex[j] = str[dec % 16];
		dec /= 16;
	}
	write(1, hex, i);
	free(hex);
	return (i);
}
