/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:06:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/02 06:06:11 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	exit_game(void)
{
	ft_printf("GAME EXITED!!\n");
	exit(0);
}

void	find_exit(void)
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
				g_game->exit_x = j;
				g_game->exit_y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	win_condition(void)
{
	if (g_game->player_x == g_game->exit_x && g_game->player_y == g_game->exit_y
		&& check_for_collect() == 0)
	{
		ft_printf("YOU WIN!!!\n");
		mlx_destroy_window(g_game->mlx, g_game->window);
		exit(0);
	}
}

int	check_for_collect(void)
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
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
