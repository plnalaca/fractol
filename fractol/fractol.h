#ifndef FRACTOL_H
# define FRACTOL_H

#include "stdio.h" // gereksizse sil
#include "unistd.h"
#include "stdlib.h"
#include "math.h"
#include "mlx/mlx.h"

#define SIZE 1024
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_core
{
	int		x;
	int		y;
	int		max_step;
	int		bpp;
	int		line_length;
	int		end;
	int		color;
    char    *name;
    void	*mlx;
	void	*window;
	void	*img;
	void	*img_ptr;
	double	j_x;
	double	j_y;
	double	zoom;
	double	off_x;
	double	off_y;
	double	cx;
	double	cy;
	double	zx;
	double	zy;

}           t_core;

void    ft_putstr_fd(char *s, int fd);
void    free_err_print(t_core *frac);
void	init_fractol(t_core *frac, char *name);
int     check_args(int ac, char **av);
int     ft_isnum(const char *str);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int	    exit_fractal(t_core *frac);
double	ft_atod(char *av);
void    draw(t_core *fractol);
int     mouse_hook(int mouse, int x, int y, t_core *fractol);
int     key_hook(int key_code, t_core *fractol);


#endif