/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:49:24 by mac               #+#    #+#             */
/*   Updated: 2022/02/18 17:24:59 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mondelbrot(t_data *img, int x, int y)
{
	int color;
	t_complex	z;
	t_complex	pr;
	int			i;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < 200 && abs_c(z) < 2)
	{
		pr = sqr_c(z);
		z.re = pr.re + 1.0 * (x - W_OP + img->x)/img->scale;
		z.im = pr.im + 1.0 * (y - H_OP + img->y)/img->scale;
		++i;
	}
	if (abs_c(z) < 2)
	{
	  color = create_rgb((int)(abs_c(z) * 777) % 255, (int)(abs_c(z) * 921) % 255, (int)(abs_c(z) * 291) % 255);
	  my_mlx_pixel_put(img, floor(x), floor(y), color);
	}
}

void	calculate_julia(t_data *img, int x, int y)
{
	int color;
	t_complex	z;
	t_complex	pr;
	int			i;

	i = 0;
	z.re = (x - W_SIZE/sqrt(2) - W_SIZE / 2 + img->x)/img->scale;
	z.im = (y - H_SIZE/ 3 - H_SIZE / 2 + img->y)/img->scale;
	while (i < 200 && abs_c(z) <= 2)
	{
		pr = sqr_c(z);
		z.re = pr.re + -0.2;
		z.im = pr.im + 0.75;
		++i;
	}
	if (abs_c(z) < 2)
	{
		color = create_rgb((int)(abs_c(z) * 777) % 255, (int)(abs_c(z) * 921) % 255, (int)(abs_c(z) * 291) % 255);
		my_mlx_pixel_put(img, floor(x), floor(y), color);
	}
}

int ft_fractol(t_data *img)
{
	int y, x;

	x = 0;
	y = 0;
	while ( y < W_SIZE)
	{
		++y;
		x = 0;
		while (x < H_SIZE)
		{
			++x;
			if (img->fractal == 'm')
				calculate_mondelbrot(img, x, y);
			else if (img->fractal == 'j')
				calculate_julia(img, x, y);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	(void) argc;
	t_data img;

	img.mlx = mlx_init();
	img.scale = 400.0;
	img.x = W_SIZE / 2;
	img.y = H_SIZE / 2;

	img.win = mlx_new_window(img.mlx, W_SIZE, H_SIZE, "Fractals");
	img.img = mlx_new_image(img.mlx,  W_SIZE, H_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.fractal = 'h';
	(void)argv;
	help_page(&img);

	mlx_hook(img.win, 17, 0, f_close, &img);
	mlx_hook(img.win, 2, 1L<<0, print_key, &img);
	mlx_hook(img.win, 4, 0, zoom, &img);
	mlx_loop(img.mlx);
}
