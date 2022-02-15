#include "fractol.h"

int help_page(t_data *help)
{
	int	i;
	char *str[5] = {"To exit         - ESC",
				  "To run Mandelbrot - M",
				  "To run Julia      - J",
				  "To navigate 		 - use arrows",
				  "To zoom use 		 - mouse wheel or z"};

	i = 0;
	while (i < 5)
	{
		mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4, (int) (H_SIZE * 0.3) + i * 50, 0xffffff,
				       str[i]);
		i++;
	}
	return (0);
}
