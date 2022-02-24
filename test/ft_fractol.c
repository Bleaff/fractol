/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:49:24 by mac               #+#    #+#             */
/*   Updated: 2022/02/24 16:09:30 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_color_pix(t_data *img, double abs, int x, int y)
{
	int	col;

	col = create_rgb((int)(abs * 777 + img->r) % 255,
			(int)(abs * 921 + img->g) % 255, (int)(abs * 291 + img->b) % 255);
	my_mlx_pixel_put(img, floor(x), floor(y), col);
}

void	calculate_mondelbrot(t_data *img, int x, int y)
{
	t_complex	z;
	t_complex	pr;
	int			i;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < 200 && abs_c(z) < 2)
	{
		pr = sqr_c(z);
		z.re = pr.re + 1.0 * (x - W_SIZE / sqrt(2) - W_SIZE / 2 + img->x)
			/ img->scale;
		z.im = pr.im + 1.0 * (y - H_SIZE / 3 - H_SIZE / 2 + img->y)
			/ img->scale;
		++i;
	}
	if (abs_c(z) < 2)
		print_color_pix(img, abs_c(z), x, y);
}

void	calculate_julia(t_data *img, int x, int y)
{
	t_complex	z;
	t_complex	pr;
	int			i;

	i = 0;
	z.re = (x - W_SIZE / sqrt(2) - W_SIZE / 2 + img->x) / img->scale;
	z.im = (y - H_SIZE / 3 - H_SIZE / 2 + img->y) / img->scale;
	while (i < 200 && abs_c(z) <= 2)
	{
		pr = sqr_c(z);
		z.re = pr.re + img->complex.re;
		z.im = pr.im + img->complex.im;
		++i;
	}
	if (abs_c(z) < 2)
		print_color_pix(img, abs_c(z), x, y);
}

int	ft_fractol(t_data *img)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < W_SIZE)
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
	t_data	img;

	init_img(&img);
	if (argc > 1 && argc <= 4)
	{
		img.fractal = argv[1][0];
		if (argv[1][0] == 'j' && argc == 4)
			process_comp(&img, argv);
		if ((argv[1][0] == 'm' && argc == 2) ||
			(argv[1][0] == 'j' && argc == 4))
			print_fractal(&img);
		else
			mlx_lhelp(&img);
	}
	else
		mlx_lhelp(&img);
	mlx_hook(img.win, 17, 0, f_close, &img);
	mlx_hook(img.win, 2, 0, print_key, &img);
	mlx_hook(img.win, 4, 0, zoom, &img);
	mlx_loop(img.mlx);
}
