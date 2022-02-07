#include "fractol.h"
#include <stdio.h>


int	f_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
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
          while (i < 100 && abs_c(z) < 2)
          {
			  pr = sqr_c(z);
              z.re = pr.re + 1.0 * (x - W_SIZE/sqrt(2))/400;
			  z.im = pr.im + 1.0 * (y - H_SIZE/ 3)/400;
              ++i;
          }
          if (abs_c(z) > 2)
          {
			  color = create_rgb((int)(abs_c(z) * 133) % 255, (int)(abs_c(z) * 1000) % 255, (int)(abs_c(z) * 2912) % 255);
			  my_mlx_pixel_put(img, floor(x), floor(y), color);
		  }
      }
	  return (1);
}

int ft_fractol_julia(t_data *img)
{
	int p = 200, iter = 100;
	int a,b;
	t_complex c, z;
	int i = 0;

	c.re = -0.2;
	c.im = 0.75;
	for (int y = -p; y < p; y++) {
		for (int x = -p; x < p; x++) {
			a = x;
			b = y;
			z.re = a;
			z.im = b;
			int good = 1;
			t_complex ans;
			while (i < iter){
				ans = sqr_c(z);
				z.re = ans.re + c.re;
				z.im = ans.im + c.im;
				i++;
				if (abs_c(z) > 2)
				{
					good = 0;
					break;
				}
			}
			if (good && i == iter)
				my_mlx_pixel_put(img, x + sqrt(2)*p, y + sqrt(2)*p, 0x0);
		}
	}
	return (1);
}


void ft_whiteboard(t_data *img)
{
	for (size_t w = 0; w < 1200; w++) {
		for (size_t h = 0; h < 600; h++) {
 			my_mlx_pixel_put(img, w, h, 0xffffff);		}
	}
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_vars	vars2;
	t_data	img2;

	vars.mlx = mlx_init();
	vars2.mlx = vars.mlx;
	vars2.win = mlx_new_window(vars.mlx, 1200, 600, "Julia");
	vars.win = mlx_new_window(vars.mlx, W_SIZE, H_SIZE, "Mondelbrot");
	img.img = mlx_new_image(vars.mlx,  W_SIZE, H_SIZE);
	img2.img = mlx_new_image(vars.mlx, 1200, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length,
								&img2.endian);
	//ft_whiteboard(&img);
	ft_whiteboard(&img2);

	ft_fractol_mondelbrot(&img);
	ft_fractol_julia(&img2);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_put_image_to_window(vars2.mlx, vars2.win, img2.img, 0, 0);

	mlx_hook(vars2.win, 2, 1L<<0, f_close, &vars2);
	mlx_loop(vars2.mlx);
}
