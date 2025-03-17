#include "fractol.h"

int	exit_fractal(t_core *frac)
{
	mlx_destroy_image(frac->mlx, frac->img);
	mlx_destroy_window(frac->mlx, frac->window);
	free(frac->mlx);
	free(frac);
	exit(1);
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isnum(const char *str)
{
	int	i;
	int	has_decimal;

	i = 0;
	has_decimal = 0;
	if (str == NULL || *str == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
    if(!ft_isdigit((unsigned char)str[i]))
        return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			if (has_decimal)
				return (0);
			has_decimal = 1;
		}
		else if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	i = 0;
	while (i < n && !(c2[i] == '\0' && c1[i] == '\0'))
	{
		if (c1[i] == c2[i])
		{
			i++;
		}
		else if (c1[i] > c2[i])
			return (1);
		else
			return (-1);
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
    }
}