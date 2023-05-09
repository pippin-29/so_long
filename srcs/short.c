/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:51:54 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/09 06:20:56 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

extern t_game	*g_game;

void	*window(char *win_name)
{
	int	x;
	int	y;

	x = g_game->grid_width * g_game->pixels;
	y = g_game->grid_height * g_game->pixels;
	return (mlx_new_window(g_game->mlx, x, y, win_name));
}

void	*read_sprite(char *filename)
{
	int	p;

	p = g_game->pixels;
	return (mlx_png_file_to_image(g_game->mlx, filename, &p, &p));
}

void	draw(void *img_ptr, int j, int i)
{
	void	*m;
	void	*w;
	int		p;

	m = g_game->mlx;
	w = g_game->window;
	p = g_game->pixels;
	mlx_put_image_to_window(m, w, img_ptr, j * p, i * p);
}

void	setup(char *ber)
{	
	struct_malloc();
	init_struct();
	grid_malloc();
	parse_map(ber);
	g_game->grid_copy = ft_tabcpy(g_game->grid, g_game->grid_copy);
	find_character();
	count_exit_collect();
	check_e_c_count();
	wall_xy_malloc();
	collect_xy_malloc();
	wall_coordinates();
	collect_coordinates();
	map_error_check();
	find_exit();
	g_game->window = window("Krea's Script");
}
