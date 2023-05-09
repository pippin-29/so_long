NAME = so_long
LIBRARY = libft/libft.a minilibx/libmlx.a
FLAGS = -Werror -Wextra -Wall
MLX = minilibx/
LIBFT = libft/
MLXFLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit -lz
CC = gcc
X86 = arch -x86_64
SOURCE = srcs/*.c


COMPILE = $(CC) $(FLAGS) $(SOURCE) $(LIBRARY) $(MLXFLAGS) -o $(NAME)

all:
		$(X86) make -C $(MLX)
		$(X86) make -C $(LIBFT)
		$(X86) $(COMPILE)

clean:

fclean: clean
		make clean -C $(MLX)
		make clean -C $(LIBFT)
		rm -rf $(NAME)

re: fclean all

# -g -fsanitize=address