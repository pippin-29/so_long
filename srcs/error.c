/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:35:52 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/07 07:21:23 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

extern t_game	*g_game;

void	map_error_check(void)
{
	int	i;

	i = 0;
	while (g_game->grid[i])
	{
		ft_printf("%s\n", g_game->grid[i]);
		i++;
	}
	if (!map_check_valid_char(g_game->grid))
	{
		perror("Error: Invalid Map Type\n");
		exit(1);
	}
	if (!map_check_shape(g_game->grid))
	{
		perror("Error: Invalid Map Shape\n");
		exit(1);
	}
	if (map_check_walls() == -1)
	{
		perror("Error: Map walls not closed in\n");
		exit(1);
	}
}

void	grid_malloc(void)
{
	g_game->grid = (char **)malloc(sizeof(char *) * MAX_HEIGHT_MAP);
	if (!g_game->grid)
	{
		perror("Error: Malloc for grid\n");
		exit(1);
	}
}

void	struct_malloc(void)
{
	g_game = malloc(sizeof(t_game));
	if (!g_game)
	{
		perror("Error: Struct\n");
		exit(1);
	}
}

void	wall_xy_malloc(void)
{
	g_game->wall_xy = malloc(sizeof(int *) * (count_walls() + 1));
	if (!g_game->wall_xy)
	{
		perror("Error: Wall Array\n");
		exit(1);
	}
}

void	collect_xy_malloc(void)
{
	g_game->collect_xy = malloc(sizeof(int *) * (g_game->collect_count + 1));
	if (!g_game->collect_xy)
	{
		perror("Error: Collectible Array\n");
		exit(1);
	}
}
