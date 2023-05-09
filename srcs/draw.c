/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:58:05 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/02 06:05:20 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

extern t_game	*g_game;

void	draw_floor(void *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_game->grid[i])
	{
		while (g_game->grid[i][j])
		{
			if (g_game->grid[i][j] == '0' || g_game->grid[i][j] == 'C'
			|| g_game->grid[i][j] == 'E' || g_game->grid[i][j] == 'P')
				draw(img, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_wall(void *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_game->grid[i])
	{
		while (g_game->grid[i][j])
		{
			if (g_game->grid[i][j] == '1')
				draw(img, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_exit(void *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_game->grid[i])
	{
		while (g_game->grid[i][j])
		{
			if (g_game->grid[i][j] == 'E')
			{
				draw(img, j, i);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_character(void *img)
{
	draw(img, g_game->player_x, g_game->player_y);
}

void	draw_collectible(void *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_game->grid[i])
	{
		while (g_game->grid[i][j])
		{
			if (g_game->grid[i][j] == 'C')
			{
				draw(img, j, i);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
