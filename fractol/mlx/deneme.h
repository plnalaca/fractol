#ifndef DENEME_H
# define DENEME_H

#include "mlx/mlx.h"

typedef struct s_list
{
    void *mlx;
    void *window;
    void *img;
    void *img_addr;
    int bpp;
    int size_line;
    int endian;
}           t_list;

#endif