/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_page.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:02:57 by bleaf             #+#    #+#             */
/*   Updated: 2022/02/22 23:25:20 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	f_close(void)
{
	exit(0);
}

void	ft_whiteboard(t_data *img, int color)
{
	int	w;
	int	h;

	w = 0;
	while (w < W_SIZE)
	{
		h = 0;
		while (h < H_SIZE)
		{
			my_mlx_pixel_put(img, w, h, color);
			h++;
		}
		w++;
	}
}

int	help_page(t_data *help)
{
	ft_whiteboard(help, 0x0);
	mlx_put_image_to_window(help->mlx, help->win, help->img, 0, 0);
	help->fractal = 'h';
	mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4,
		(int)(H_SIZE * 0.3), 0xffffff, "To exit................- ESC");
	mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4,
		(int)(H_SIZE * 0.3 + 50), 0xffffff, "To run Mandelbrot........- m");
	mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4,
		(int)(H_SIZE * 0.3 + 100), 0xffffff, "To run Julia.............- j");
	mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4,
		(int)(H_SIZE * 0.3 + 150),
		0xffffff, "To navigate..............- use arrows");
	mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4,
		(int)(H_SIZE * 0.3 + 200),
		0xffffff, "To zoom use..............- mouse wheel or z");
	mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4,
		(int)(H_SIZE * 0.3 + 250), 0xffffff, "To return to help-page...- h");
	mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4,
		(int)(H_SIZE * 0.3 + 300), 0xffffff, "To change rgb............-r/g/b");
	mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4,
		(int)(H_SIZE * 0.3 + 350), 0xffffff,
		"Example command for Julia: j -0.37 0.85");
	mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4,
		(int)(H_SIZE * 0.3 + 400), 0xffffff, "Examp command for Mondel: m");
	return (0);
}
