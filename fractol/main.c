#include "fractol.h"

int main(int ac, char **av)
{
    t_core  *frac;

    frac = malloc(sizeof(t_core));
    if (!frac)
        return (0);
    if (check_args(ac, av))
        free_err_print(frac);
    init_fractol(frac, av[1]);
    if (ac != 4)
        draw(frac);
    else if (ac == 4)
    {
        frac->j_x = ft_atod(av[2]);
        frac->j_y = ft_atod(av[3]);
        draw(frac);
    }
    mlx_key_hook(frac->window, key_hook, frac);
	mlx_mouse_hook(frac->window, mouse_hook, frac);
	mlx_hook(frac->window, 17, 0L, exit_fractal, frac);
	mlx_loop(frac->mlx);
	free(frac);
    return (0);
}
