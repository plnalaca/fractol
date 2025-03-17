#include "fractol.h"

static void	zoom(t_core *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->off_x = (x / fractal->zoom + fractal->off_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->off_y = (y / fractal->zoom + fractal->off_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->off_x = (x / fractal->zoom + fractal->off_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->off_y = (y / fractal->zoom + fractal->off_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

int	key_hook(int key_code, t_core *fractol)
{
	if (key_code == ESC)
		exit_fractal(fractol);
	else if (key_code == LEFT)
		fractol->off_x -= 42 / fractol->zoom;
	else if (key_code == RIGHT)
		fractol->off_x += 42 / fractol->zoom;
	else if (key_code == UP)
		fractol->off_y -= 42 / fractol->zoom;
	else if (key_code == DOWN)
		fractol->off_y += 42 / fractol->zoom;
	draw(fractol);
	return (0);
}

int	mouse_hook(int mouse, int x, int y, t_core *fractol)
{
	if (mouse == SCROLL_UP)
		zoom(fractol, x, y, 1);
	else if (mouse == SCROLL_DOWN)
		zoom(fractol, x, y, -1);
	draw(fractol);
	return (0);
}
