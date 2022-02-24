/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:06:33 by bleaf             #+#    #+#             */
/*   Updated: 2022/02/24 16:13:37 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	esc_close(int keycode, void *img)
{
	(void)img;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	init_img(t_data *img)
{
	img->mlx = mlx_init();
	img->scale = 400.0;
	img->x = W_SIZE / 2;
	img->y = H_SIZE / 2;
	img->r = 0;
	img->g = 0;
	img->b = 0;
	img->complex.re = -0.2;
	img->complex.im = 0.75;
	img->win = mlx_new_window(img->mlx, W_SIZE, H_SIZE, "Fractals");
	img->img = mlx_new_image(img->mlx, W_SIZE, H_SIZE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->fractal = 'h';
}

void	mlx_lhelp(t_data *img)
{
	help_page(img);
	mlx_hook(img->win, 17, 0, f_close, img);
	mlx_hook(img->win, 2, 0, esc_close, img);
	mlx_loop(img->mlx);
}
