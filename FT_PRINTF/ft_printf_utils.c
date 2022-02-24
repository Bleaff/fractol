/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:12:29 by bleaf             #+#    #+#             */
/*   Updated: 2022/01/12 01:08:15 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	get_nb_size(int nb)
{
	size_t	i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static int	get_nb_length(int nb)
{
	long int	i;

	i = 1;
	if (nb < 0)
		nb *= -1;
	while (nb)
	{
		i *= 10;
		nb /= 10;
	}
	i /= 10;
	return (i);
}

static void	fill_arr(long int lnb, long int size_reg, char *arr, int sign)
{
	char	temp;
	int		i;

	i = 0;
	if (sign)
		arr[i++] = '-';
	while (size_reg)
	{
		temp = 48 + lnb / size_reg % 10;
		arr[i++] = temp;
		size_reg /= 10;
	}
	arr[i] = '\0';
}

char	*ft_itoa(int n)
{
	long int	lnb;
	long int	size_reg;
	char		*new;
	int			sign;

	sign = 0;
	size_reg = get_nb_length(n);
	if (!n)
	{
		new = (char *)malloc(sizeof(char) * 2);
		new[0] = '0';
		new[1] = '\0';
		return (new);
	}
	lnb = n;
	if (n < 0)
	{
		lnb *= -1;
		sign++;
	}
	new = (char *)malloc(sizeof(char) * (get_nb_size(size_reg) + sign + 1));
	if (!new)
		return (NULL);
	fill_arr(lnb, size_reg, new, sign);
	return (new);
}
