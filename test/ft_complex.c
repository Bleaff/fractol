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
