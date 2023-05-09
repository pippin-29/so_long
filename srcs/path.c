/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:34:21 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/09 06:23:24 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

extern t_game	*g_game;

void	check_path(char paint, int y, int x)
{
	if (g_game->grid_copy[y][x] == '1')
		return ;
	else if (g_game->grid_copy[y][x] == 'C')
	{
		g_game->grid_copy[y][x] = 'F';
		g_game->collect_count_copy++;
	}
	else if (g_game->grid_copy[y][x] == 'E')
	{
		g_game->grid_copy[y][x] = 'F';
		g_game->exit_count_copy++;
	}
	else if (g_game->grid_copy[y][x] == '0' || g_game->grid_copy[y][x] == 'P')
	{
		g_game->grid_copy[y][x] = paint;
		check_path(paint, y, x + 1);
		check_path(paint, y, x - 1);
		check_path(paint, y + 1, x);
		check_path(paint, y - 1, x);
	}
}

void	check_e_c_count(void)
{
	check_path('F', g_game->player_y, g_game->player_x);
	if (g_game->collect_count_copy != g_game->collect_count
		|| g_game->exit_count_copy != g_game->exit_count)
	{
		perror("Error: Map has no valid path!\n");
		exit(1);
	}
	else
	{
		ft_printf("Map has valid path!\n");
	}
}
