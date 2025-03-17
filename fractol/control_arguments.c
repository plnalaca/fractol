#include "fractol.h"

static	char	*get_sign(char *av, int *sign)
{
	*sign = 1;
	while (*av == ' ' || (*av >= '\t' && *av <= '\r'))
		av++;
	if (*av == '-' || *av == '+')
	{
		if (*av == '-')
			*sign = -1;
		av++;
	}
	return (av);
}

static	double	broken_number(char *av, double db_num, double div_num)
{
	double	result;

	result = 0.0;
	while (*av >= '0' && *av <= '9')
	{
		result = result * 10.0 + (*av - '0');
		av++;
	}
	if (*av == '.')
	{
		av++;
		while (*av >= '0' && *av <= '9')
		{
			db_num = db_num * 10.0 + (*av - '0');
			div_num*= 10.0;
			av++;
		}
		result += db_num / div_num;
	}
	return (result);
}

double	ft_atod(char *av)
{
	double	result;
	double	db_num;
	double	div_num;
	int		sign;

	result = 0;
	db_num = 0.0;
	div_num = 1.0;
	sign = 0;
	av = get_sign(av, &sign);
	result = broken_number(av, db_num, div_num);
	return (result * sign);
}
void free_err_print(t_core *frac)
{
    ft_putstr_fd(" Please write right arguments.\n", 1);
	free(frac);
	exit(1);
}

int	check_args(int ac, char **av)
{
    if (!(ac == 4 || ac == 2))
		return(1);
    if (ac == 4 && ((!ft_isnum(av[2])) || (!ft_isnum(av[3]))))
		return(1);
	if (!((ac == 2 && !ft_strncmp(av[1], "mbrot", 5))
			|| (ac == 4 && !ft_strncmp(av[1], "julia", 5))
			|| (ac == 2 && !ft_strncmp(av[1], "julia", 5))))
		return(1);
	if (ac == 4 && (ft_atod(av[3]) > __DBL_MAX__
			|| ft_atod(av[2]) > __DBL_MAX__
			|| ft_atod(av[2]) < ((__DBL_MAX__ + 1) * -1)
			|| ft_atod(av[3]) < ((__DBL_MAX__ + 1) * -1)))
		return(1);
    return (0);
}