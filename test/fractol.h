#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"
# define W_SIZE 1080
# define H_SIZE 1080



typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_complex {
  double re;
  double im;
}	t_complex;

int	f_close(t_vars *vars);
int create_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

double abs_c(t_complex c);
t_complex sum_c(t_complex a, t_complex b);
t_complex sqr_c(t_complex c);

int main(void);
#endif
