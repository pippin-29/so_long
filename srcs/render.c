/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 07:44:10 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/02 10:20:56 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	render(void *param)
{
	(void)param;
	win_condition();
	collect_condition();
	mlx_clear_window(g_game->mlx, g_game->window);
	draw_wall(g_game->wall_sprite);
	draw_floor(g_game->floor_sprite);
	draw_exit(g_game->exit_sprite);
	draw_collectible(g_game->collect_sprite);
	draw_character(g_game->character_sprite);
	return (0);
}
