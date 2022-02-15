#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
#include <stdio.h>

# include "../minilibx/mlx.h"
# define W_SIZE 1080
# define H_SIZE 1080


enum STATES{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_complex {
  double re;
  double im;
}	t_complex;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_complex complex;
	double scale;
	int x;
	int y;
}				t_data;

int	f_close(void);
int create_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

double abs_c(t_complex c);
t_complex sum_c(t_complex a, t_complex b);
t_complex sqr_c(t_complex c);

int help_page(t_data *help);


int main(void);
#endif
