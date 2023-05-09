/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:57:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/06 23:22:51 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

t_game	*g_game;

void	init_struct(void)
{
	g_game->grid = NULL;
	g_game->grid_copy = NULL;
	g_game->grid_height = 0;
	g_game->grid_width = 0;
	g_game->mlx = mlx_init();
	g_game->pixels = 32;
	g_game->moves = 0;
	g_game->player_x = -1;
	g_game->player_y = -1;
	g_game->window = NULL;
	g_game->exit_x = -1;
	g_game->exit_y = -1;
	g_game->exit_count = 0;
	g_game->exit_count_copy = 0;
	g_game->floor_sprite = read_sprite("img/floor.png");
	g_game->exit_sprite = read_sprite("img/exit.png");
	g_game->character_sprite = read_sprite("img/character.png");
	g_game->collect_sprite = read_sprite("img/collectible.png");
	g_game->wall_sprite = read_sprite("img/wall.png");
	g_game->collect_xy = NULL;
	g_game->collect_count = 0;
	g_game->collect_count_copy = 0;
	g_game->wall_xy = NULL;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		setup(argv[1]);
		mlx_hook(g_game->window, 2, 1L << 0, handle_keypress, NULL);
		mlx_loop_hook(g_game->mlx, render, NULL);
		mlx_loop(g_game->mlx);
	}
	else
	{
		ft_printf("Please Enter 1 Argument in the form of a .ber file!\n");
		ft_printf("File must be in root of directory!\n");
		exit(1);
	}
}
