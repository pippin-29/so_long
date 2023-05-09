/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:29:11 by dhadding          #+#    #+#             */
/*   Updated: 2023/04/30 17:25:56 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

extern t_game	*g_game;

int	is_wall(int x, int y)
{
	int	i;

	i = count_walls() - 1;
	while (i >= 0)
	{
		if (x == g_game->wall_xy[i][0] && y == g_game->wall_xy[i][1])
			return (1);
		i--;
	}
	return (0);
}

int	count_walls(void)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (g_game->grid[i])
	{
		while (g_game->grid[i][j])
		{
			if (g_game->grid[i][j] == '1')
			{
				count++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	wall_coordinates(void)
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
			if (g_game->grid[i][j] == '1')
			{
				g_game->wall_xy[c] = malloc(sizeof(int) * 2);
				g_game->wall_xy[c][0] = j;
				g_game->wall_xy[c][1] = i;
				c++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
