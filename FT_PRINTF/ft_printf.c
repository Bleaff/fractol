/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:31:51 by bleaf             #+#    #+#             */
/*   Updated: 2022/01/12 03:28:32 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_num_arg(va_list list, char descr)
{
	char	*str;
	int		wr;

	wr = 0;
	if (!list || descr <= 0)
		return (0);
	else if (descr == 'p')
		return (ft_put_pointer(va_arg(list, unsigned long)));
	else if (descr == 'u')
		return (ft_put_unsign(va_arg(list, unsigned int)));
	else if (descr == 'd' || descr == 'i')
	{
		str = ft_itoa(va_arg(list, int));
		if (!str)
			return (write(1, "(null)", 6));
		wr = write(1, str, ft_strlen(str));
		free(str);
		return (wr);
	}
	else
		return (ft_put_str_arg(list, descr));
	return (0);
}

int	ft_put_str_arg(va_list list, char descr)
{
	char	*str;

	if (!list || descr <= 0)
		return (0);
	else if (descr == 'c')
	{
		ft_putchar_fd(va_arg(list, int), 1);
		return (1);
	}
	else if (descr == 's')
	{
		str = va_arg(list, char *);
		if (!str)
			return (write(1, "(null)", 6));
		return (write(1, str, ft_strlen(str)));
	}
	else if (descr == '%')
		return (write(1, &descr, 1));
	else if (descr == 'x')
		return (ft_put_hex(va_arg(list, unsigned int), 1));
	else if (descr == 'X')
		return (ft_put_hex(va_arg(list, unsigned int), 0));
	return (0);
}

int	ft_valid_ch(int ch)
{
	char	*correct_sym;

	correct_sym = "cspdiuxX%";
	if (!correct_sym || ch == '\0')
		return (-1);
	while (correct_sym)
	{
		if (*correct_sym == (char) ch)
		{
			return (1);
		}
		correct_sym++;
	}
	return (0);
}

static int	ft_procnpr_str(const char *line, va_list ls)
{
	int		i;
	int		written;

	if (!line)
		return (0);
	i = 0;
	written = 0;
	while (line[i])
	{
		if (line[i] == '%' && ft_valid_ch(line[i + 1]) == 1)
		{
			written += ft_put_num_arg(ls, line[i + 1]);
			i += 2;
			continue ;
		}
		written += write(1, &line[i++], 1);
	}
	return (written);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;

	if (!str)
	{
		return (0);
	}
	va_start(list, str);
	return (ft_procnpr_str(str, list));
}
