NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLX_DIR = mlx

MLX = $(MLX_DIR)/libmlx.a

LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS = main.c
   	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBS)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re