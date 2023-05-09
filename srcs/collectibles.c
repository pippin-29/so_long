/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:13:15 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/01 15:32:14 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

extern t_game	*g_game;

void	collect_coordinates(void)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (g_game->grid[i])
	{
		while (g_game->grid[i][j])
		{
			if (g_game->grid[i][j] == 'C')
			{
				g_game->collect_xy[c] = malloc(sizeof(int) * 3);
				g_game->collect_xy[c][0] = j;
				g_game->collect_xy[c][1] = i;
				c++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	g_game->collect_xy[c] = NULL;
}

void	collect_condition(void)
{
	int	i;

	i = 0;
	while (g_game->collect_xy[i] != NULL)
	{
		if (g_game->collect_xy[i][0] == g_game->player_x
		&& g_game->collect_xy[i][1] == g_game->player_y)
		{
			g_game->grid[g_game->player_y][g_game->player_x] = '0';
		}
		i++;
	}
}

void	count_exit_collect(void)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (g_game->grid[i])
	{
		while (g_game->grid[i][j])
		{
			if (g_game->grid[i][j] == 'E')
				g_game->exit_count++;
			if (g_game->grid[i][j] == 'C')
				g_game->collect_count++;
			j++;
		}
		j = 0;
		i++;
	}
}
