#include "fractol.h"

void ft_whiteboard(t_data *img, int color)
{
	for (size_t w = 0; w < W_SIZE; w++) {
		for (size_t h = 0; h < H_SIZE; h++) {
 			my_mlx_pixel_put(img, w, h, color);
		}
	}
}

int help_page(t_data *help)
{
	ft_whiteboard(help, 0x0);
	mlx_put_image_to_window(help->mlx, help->win, help->img, 0, 0);
	int	i;
	char *str[6] = {"To exit................- ESC",
				  "To run Mandelbrot........- m",
				  "To run Julia.............- j",
				  "To navigate..............- use arrows",
				  "To zoom use..............- mouse wheel or z",
				  "To return to help-page...- h"
			  };

	i = 0;
	help->fractal = 'h';
	while (i < 6)
	{
		mlx_string_put(help->mlx, help->win, (int)W_SIZE * 0.4, (int) (H_SIZE * 0.3) + i * 50, 0xffffff,
				       str[i]);
		i++;
	}
	return (0);
}
