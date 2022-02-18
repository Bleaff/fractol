#include "fractol.h"

int	f_close(void)
{
	exit(0);
}

int print_fractal(t_data *img)
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
	printf("%d\n", keycode);
	if ((keycode == ON_MOUSEUP || keycode == ON_MOUSEDOWN) && img_old->fractal !='h')
	{
		img_old->x = x;
		img_old->y = y;
		if(keycode == ON_MOUSEUP)
			img_old->scale *= 1.5;
		else
			img_old->scale /= 1.1;
		print_fractal(img_old); // ERRORS!
	}
	return (0);
}

int print_key(int keycode,void *param)
{
	t_data	*check;

	check = (t_data *)param;
	printf("%d keycode\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 46)
	{
		check->fractal = 'm';
		print_fractal(check);
	}
	else if (keycode == 6 && check->fractal != 'h')
	{
		check->scale *= 1.5;
		print_fractal(check);
	}
	else if (keycode == 126 && check->fractal != 'h')
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
	else if (keycode == 38)
	{
		check->fractal = 'j';
		print_fractal(check);
	}
	else if (keycode == 4)
	{
		check->fractal = 'j';
		help_page(check);
	}
	return (0);
}
