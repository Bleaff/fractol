/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:44:41 by bleaf             #+#    #+#             */
/*   Updated: 2022/02/22 23:48:14 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isalpha(int ch)
{
	if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long long	num;
	int			sign;

	sign = 1;
	num = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\r' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		if (-2147483648 > num * sign)
			return (0);
		else if (2147483647 < num * sign)
			return (-1);
		num *= 10;
		num += *nptr++ - '0';
	}
	return (num * sign);
}

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;
	int		neg;

	neg = 0;
	c = (char *)str;
	res = (double)ft_atoi(c);
	if (c[0] == '-')
		neg = -1;
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (neg == -1)
		return (res - res2);
	else
		return (res + res2);
}

void	process_comp(t_data *img, char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 2;
	while (j < 4)
	{
		while (i < ft_strlen(argv[j]))
		{
			if (ft_isalpha(argv[j][i++]))
			{
				ft_printf("Incorrect symbol! (%c)\n", argv[j][i]);
				exit(-1);
			}
		}
		j++;
		i = 0;
	}
	img->complex.re = ft_atof(argv[2]);
	img->complex.im = ft_atof(argv[3]);
}
