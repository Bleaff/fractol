/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:12:41 by bleaf             #+#    #+#             */
/*   Updated: 2022/02/24 16:13:52 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "../minilibx/mlx.h"
# include "../FT_PRINTF/ft_printf.h"
# define W_SIZE 1080
# define H_SIZE 1080
# define ITERATE 150

enum e_states{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_complex {
	double	re;
	double	im;
}	t_complex;

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_complex	complex;
	double		scale;
	int			x;
	int			y;
	char		fractal;
	int			r;
	int			g;
	int			b;
}				t_data;

int			f_close(void);
int			create_rgb(int r, int g, int b);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		calculate_julia(t_data *img, int x, int y);
void		calculate_mondelbrot(t_data *img, int x, int y);
int			ft_fractol(t_data *img);
void		print_color_pix(t_data *img, double abs, int x, int y);

void		ft_whiteboard(t_data *img, int color);
int			print_fractal(t_data *img);
int			zoom(int keycode, int x, int y, void *img);
int			print_key(int keycode, void *param);
void		ft_process_arrows(int keycode, t_data *check);
void		ft_choose_fractal(int keycode, t_data *check);

double		abs_c(t_complex c);
t_complex	sum_c(t_complex a, t_complex b);
t_complex	sqr_c(t_complex c);

int			help_page(t_data *help);

void		init_img(t_data *img);
void		mlx_lhelp(t_data *img);
int			main(int argc, char **argv);

double		ft_atof(const char *str);
void		process_comp(t_data *img, char **argv);
#endif
