#include "fractol.h"

double abs_c(t_complex c)
{
	return (sqrt(c.re * c.re + c.im * c.im));
}

t_complex sum_c(t_complex a, t_complex b)
{
	t_complex ans;
	ans.re = a.re + b.re;
	ans.im = a.im + b.im;
	return (ans);
}

t_complex sqr_c(t_complex c)
{
	t_complex ans;

	ans.re = (c.re * c.re)  - (c.im * c.im);
	ans.im =  2 * c.re * c.im;
 	return (ans);
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
