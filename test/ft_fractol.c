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
              z.re = pr.re + 1.0 * (x - W_SIZE/sqrt(2))/img->scale;
			  z.im = pr.im + 1.0 * (y - H_SIZE/ 3)/img->scale;
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

// int	zoom(int keycode, void *img_old)
// {
// 	t_data *_c;
//
// 	_c = (t_data *)img_old;
// 	printf("%d\n", keycode);
//
// 	if (keycode == ON_MOUSEUP)
// 	{
// 		t_data &img;
// 		img->scale = 2 * _c->scale;
// 		img->win = _c->win;
// 		img->mlx = _c->mlx;
// 		img->img = mlx_new_image(img->mlx,  W_SIZE, H_SIZE);
// 		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
// 		ft_whiteboard(img, 0x0);
// 		ft_fractol_mondelbrot(img);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
// 	}
// 	return (0);
// }

int print_key(int keycode, void *param)
{
	t_data	*check;

	check = (t_data *)param;
	printf("%d keycode\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 46)
	{
		ft_whiteboard(check, 0x0);
		ft_fractol_mondelbrot(check);
		mlx_put_image_to_window(check->mlx, check->win, check->img, 0, 0);
	}
	if (keycode == 6)
	{
		check->scale *= 3;
		ft_whiteboard(check, 0x0);
		ft_fractol_mondelbrot(check);
		mlx_put_image_to_window(check->mlx, check->win, check->img, 0, 0);
	}
	return (0);
}



int	main(void)
{
	t_data img;

	img.mlx = mlx_init();
	img.scale = 400.0;

	img.win = mlx_new_window(img.mlx, W_SIZE, H_SIZE, "Fractals");

	img.img = mlx_new_image(img.mlx,  W_SIZE, H_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("FUCK\n");

	help_page(&img);
	printf("FUCK\n");

	mlx_hook(img.win, 17, 1L<<5, f_close, &img);
	mlx_hook(img.win, 2, 1L<<0, print_key, &img);
	//mlx_hook(img.win, 4, 1L<<0, zoom, &img);

	mlx_loop(img.mlx);
}
