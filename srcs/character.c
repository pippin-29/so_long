/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:06:04 by dhadding          #+#    #+#             */
/*   Updated: 2023/04/30 08:07:43 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

extern t_game	*g_game;

void	find_character(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_game->grid[i])
	{
		while (g_game->grid[i][j])
		{
			if (g_game->grid[i][j] == 'P')
			{
				g_game->player_x = j;
				g_game->player_y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
