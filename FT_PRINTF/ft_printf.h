/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:52:12 by bleaf             #+#    #+#             */
/*   Updated: 2022/01/12 01:22:53 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_put_str_arg(va_list list, char descr);
int				ft_put_num_arg(va_list list, char descr);
int				ft_put_unsign(unsigned int ui);
int				ft_put_pointer(unsigned long ul);
int				ft_put_hex(unsigned int dec, int flag);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *s);
void			ft_putchar_fd(char c, int fd);
int				ft_get_unb_len(unsigned int nb, int del);
int				ft_get_ul_len(unsigned long nb);
unsigned int	ft_pow(int num, int pow);
unsigned long	ft_ulpow(int num, int pow);
#endif
