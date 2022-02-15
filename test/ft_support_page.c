#include "fractol.h"

int help_page(t_datvar *help)
{
	int	i;
	char *str[3] = {"To exit           - ESC",
				  "To run Mandelbrot - M",
				  "To run Julia      - J"};

	printf("FUCK1\n");
	i = 0;
	while (i < 3)
	{
		mlx_string_put(&help->vars->mlx, &help->vars->win, (int)W_SIZE * 0.4, (int) (H_SIZE * 0.3) + i * 50, 0xffffff,
				       str[i]);
		i++;
		printf("FUCK2\n");
	}
	return (0);
}
