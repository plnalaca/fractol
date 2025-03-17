#include "fractol.h"

static void fill_color(int x, int y, t_core *frac, int color)
{
    int *tmp;

    tmp = (int *)frac->img_ptr;
    tmp[y * (frac->line_length / 4) + x] = color;
}
static void create_m(t_core *frac)
{
    int i;
    double tmp;

    i = -1;
    frac->zx = 0.0;
    frac->zy = 0.0;
    frac->cx = (frac->x / frac->zoom) + frac->off_x;
    frac->cy = (frac->y / frac->zoom) + frac->off_y;
    while(i < frac->max_step)
    {
        tmp = (frac->zx * frac->zx) - (frac->zy * frac->zy) + frac->cx;
        frac->zy = 2.0 * frac->zy * frac->zx + frac->cy;
        frac->zx = tmp;
        if (frac->zx * frac->zx + frac->zy
			* frac->zy >= __DBL_MAX__)
			break ;
        i++;
    }
    if(i == frac->max_step)
        fill_color(frac->x, frac->y, frac, 0);
	else
		fill_color(frac->x, frac->y, frac, frac->color * i);
}

static void create_j(t_core *frac)
{
    int i;
    double tmp;

    i = -1;
    frac->cx = frac->j_x;
    frac->cy = frac->j_y;
    frac->zx = (frac->x / frac->zoom) + frac->off_x;
    frac->zy = (frac->y / frac->zoom) + frac->off_y;
    while(i < frac->max_step)
    {
        tmp = (frac->zx * frac->zx) - (frac->zy * frac->zy) + frac->cx;
        frac->zy = 2.0 * frac->zy * frac->zx + frac->cy;
        frac->zx = tmp;
        if (frac->zx * frac->zx + frac->zy
			* frac->zy >= __DBL_MAX__)
			break ;
        i++;
    }
    if(i == frac->max_step)
        fill_color(frac->x, frac->y, frac, 0);
	else
		fill_color(frac->x, frac->y, frac, frac->color * i);
}

void draw(t_core *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < SIZE)
	{
		while (fractol->y < SIZE)
		{
            if (ft_strncmp(fractol->name, "mbrot", 5) == 0)
			{
                create_m(fractol);
			    (fractol->y)++;
            }
            else if (ft_strncmp(fractol->name, "julia", 5) == 0)
			{
                create_j(fractol);
			    (fractol->y)++;
            }
		}
		(fractol->y) = 0;
		(fractol->x)++;
	}
    mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img, 0, 0);
}
