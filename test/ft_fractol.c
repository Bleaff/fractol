#include "fractol.h"


int	f_close(void)
{
	exit(0);
}




int create_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int ft_fractol_mondelbrot(t_data *img)
{
	int color;
	t_complex z;
	t_complex pr;

	for (int y = 0; y < W_SIZE; ++y)
      for (int x = 0; x < H_SIZE; ++x)
      {
		  z.re = 0;
		  z.im = 0;
          int i = 0;
          while (i < 2000 && abs_c(z) < 2)
          {
			  pr = sqr_c(z);
              z.re = pr.re + 1.0 * (x - W_SIZE/sqrt(2))/400;
			  z.im = pr.im + 1.0 * (y - H_SIZE/ 3)/400;
              ++i;
          }
          if (abs_c(z) < 2)
          {
			  color = create_rgb((int)(abs_c(z) * 777) % 255, (int)(abs_c(z) * 9321) % 255, (int)(abs_c(z) * 2912) % 255);
			  my_mlx_pixel_put(img, floor(x), floor(y), color);
		  }
      }
	  return (1);
}

int ft_fractol_julia(t_data *img, int color_scheme)
{
	int color;
	t_complex z;
	t_complex pr;
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
			z.re = (double)(x - W_SIZE/sqrt(2))/400;
			z.im = (double)(y - H_SIZE/ 3)/400;
			int i = 0;
			while (i < 100 && abs_c(z) <= 2)
			{
				pr = sqr_c(z);
				z.re = pr.re + -0.2;
				z.im = pr.im + 0.75;
				++i;
			}
			if (abs_c(z) < 2)
			{
				color = create_rgb((int)(abs_c(z) * color_scheme) % 255, (int)(abs_c(z) * color_scheme * 7) % 255, (int)(abs_c(z) * color_scheme * 13) % 255);
				my_mlx_pixel_put(img, floor(x), floor(y), color);
			}
		}
	}
	return (1);
}

void ft_whiteboard(t_data *img, int color)
{
	for (size_t w = 0; w < W_SIZE; w++) {
		for (size_t h = 0; h < H_SIZE; h++) {
 			my_mlx_pixel_put(img, w, h, color);		}
	}
}

int print_key(int keycode, void *param)
{
	t_datvar	*check;

	check = (t_datvar *)param;
	printf("%d keycode\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 46)
	{
		ft_whiteboard(check->img, 0x0);
		ft_fractol_mondelbrot(check->img);
	}
	return (0);
}

int	main(void)
{
	t_datvar *var_img;
	printf("FUCK\n");

	var_img = NULL;
	&var_img->vars->mlx = mlx_init();
	printf("FUCK_1\n");
	var_img->vars->win = mlx_new_window(var_img->vars->mlx, W_SIZE, H_SIZE, "Fractals");
	printf("FUCK__1\n");
	var_img->img->img = mlx_new_image(var_img->vars->mlx,  W_SIZE, H_SIZE);
	printf("FUCK___1\n");
	var_img->img->addr = mlx_get_data_addr(var_img->img->img, &var_img->img->bits_per_pixel, &var_img->img->line_length, &var_img->img->endian);
	help_page(var_img);
	printf("FUCK_________\n");
	mlx_hook(var_img->vars->win, 17, 1L<<5, f_close, var_img);
	mlx_hook(var_img->vars->win, 2, 1L<<0, print_key, var_img);

	mlx_loop(var_img->vars->mlx);
}
