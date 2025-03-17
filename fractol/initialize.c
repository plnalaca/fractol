#include "fractol.h"

void	init_fractol(t_core *frac, char *name)
{
	frac->x = 0;
	frac->y = 0;
	frac->j_x = -0.7;
	frac->j_y = 0.2715;
	frac->color = 0x0721FF;
	frac->zoom = 400;
	frac->off_x = -2;
	frac->off_y = -0.3;
	frac->max_step = 420;
    frac->name = name;
	frac->mlx = mlx_init();
	frac->window = mlx_new_window(frac->mlx, SIZE, SIZE, "Fractol");
	frac->img = mlx_new_image(frac->mlx, SIZE, SIZE);
	if (!(frac->mlx) || !(frac->img) || !(frac->window))
		exit_fractal(frac);
	frac->img_ptr = mlx_get_data_addr(frac->img,
			&frac->bpp,
			&frac->line_length,
			&frac->end);
}