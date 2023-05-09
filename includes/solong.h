/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:57:57 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/09 06:22:13 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <stdio.h>

# define MAX_HEIGHT_MAP 25
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define ESC_KEY 53

typedef struct s_game
{
	int		grid_width;
	int		grid_height;
	char	**grid;
	char	**grid_copy;
	int		**wall_xy;
	int		**collect_xy;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		exit_count;
	int		collect_count;
	int		exit_count_copy;
	int		collect_count_copy;
	int		pixels;
	int		moves;
	void	*floor_sprite;
	void	*wall_sprite;
	void	*character_sprite;
	void	*collect_sprite;
	void	*exit_sprite;
	void	*mlx;
	void	*window;
}		t_game;

extern t_game	*g_game;

/* MAIN */
void	init_struct(void);

/* ERROR */
void	map_error_check(void);
void	grid_malloc(void);
void	struct_malloc(void);
void	wall_xy_malloc(void);
void	collect_xy_malloc(void);

/* MAP */
void	parse_map(char *filename);
int		map_check_valid_char(char **grid);
int		map_check_shape(char **grid);
int		map_check_walls(void);
void	parse_map_while_loop(int fd, char *line, int *i);

/* SHORT */
void	*read_sprite(char *filename);
void	*window(char *win_name);
void	draw(void *img_ptr, int j, int i);
void	setup(char *ber);

/* DRAW */
void	draw_floor(void *img);
void	draw_wall(void *img);
void	draw_collectible(void *img);
void	draw_exit(void *img);
void	draw_character(void *img);

/* COLLECTIBLES */
void	collect_coordinates(void);
void	collect_condition(void);
void	count_exit_collect(void);

/* CHARACTER */
void	find_character(void);

/* KEYPRESS */
int		handle_keypress(int keycode);
void	move_right(void);
void	move_left(void);
void	move_up(void);
void	move_down(void);

/* EXIT */
void	find_exit(void);
void	exit_game(void);
void	win_condition(void);
int		check_for_collect(void);

/* RENDER */
int		render(void *param);

/* WALL */
int		count_walls(void);
int		is_wall(int x, int y);
void	wall_coordinates(void);

/* PATH */
void	check_path(char paint, int y, int x);
void	check_e_c_count(void);

#endif