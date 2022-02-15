#include "fractol.h"

int print_key(int keycode, void *param)
{
	printf("%d keycode\n", keycode);
	void(param);
	return (0);
}
