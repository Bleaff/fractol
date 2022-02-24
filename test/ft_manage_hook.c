/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:02:48 by bleaf             #+#    #+#             */
/*   Updated: 2022/02/23 00:05:38 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_fractal(t_data *img)
{
	ft_whiteboard(img, 0x0);
	ft_fractol(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int	zoom(int keycode, int x, int y, void *img)
{
	t_data	*img_old;

	img_old = (t_data *)img;
	if ((keycode == ON_MOUSEUP || keycode == ON_MOUSEDOWN)
		&& img_old->fractal != 'h')
	{
		img_old->x = x;
		img_old->y = y;
		if (keycode == ON_MOUSEUP)
			img_old->scale *= 1.5;
		else
			img_old->scale /= 1.1;
		print_fractal(img_old);
	}
	return (0);
}

void	ft_process_arrows(int keycode, t_data *check)
{
	if (keycode == 126 && check->fractal != 'h')
	{
		check->y -= 300;
		print_fractal(check);
	}
	else if (keycode == 125 && check->fractal != 'h')
	{
		check->y += 300;
		print_fractal(check);
	}
	else if (keycode == 123 && check->fractal != 'h')
	{
		check->x -= 300;
		print_fractal(check);
	}
	else if (keycode == 124 && check->fractal != 'h')
	{
		check->x += 300;
		print_fractal(check);
	}
}

void	ft_choose_fractal(int keycode, t_data *check)
{
	if (keycode == 46)
	{
		check->fractal = 'm';
		print_fractal(check);
	}
	else if (keycode == 38)
	{
		check->fractal = 'j';
		print_fractal(check);
	}
	else if (keycode == 15 && check->fractal != 'h')
	{
		check->r += 10;
		print_fractal(check);
	}
	else if (keycode == 5 && check->fractal != 'h')
	{
		check->g += 10;
		print_fractal(check);
	}
	else if (keycode == 11 && check->fractal != 'h')
	{
		check->b += 10;
		print_fractal(check);
	}
}

int	print_key(int keycode, void *param)
{
	t_data	*check;

	check = (t_data *)param;
	if (keycode == 53)
		exit(0);
	else if (keycode == 6 && check->fractal != 'h')
	{
		check->scale *= 1.5;
		print_fractal(check);
	}
	else if (keycode == 4)
	{
		check->fractal = 'h';
		help_page(check);
	}
	ft_choose_fractal(keycode, check);
	ft_process_arrows(keycode, check);
	return (0);
}
