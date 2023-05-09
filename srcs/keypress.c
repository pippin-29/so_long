/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:36:58 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/02 06:07:55 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

extern t_game	*g_game;

int	handle_keypress(int keycode)
{
	if (keycode == KEY_UP)
		move_up();
	else if (keycode == KEY_DOWN)
		move_down();
	else if (keycode == KEY_RIGHT)
		move_right();
	else if (keycode == KEY_LEFT)
		move_left();
	else if (keycode == ESC_KEY)
		exit_game();
	return (0);
}

void	move_right(void)
{
	if (!is_wall(g_game->player_x + 1, g_game->player_y))
	{
		g_game->moves++;
		g_game->player_x++;
		ft_printf("Moves: %d\n", g_game->moves);
	}
	ft_printf("Right key Pressed!\n");
}

void	move_left(void)
{
	if (!is_wall(g_game->player_x - 1, g_game->player_y))
	{
		g_game->moves++;
		g_game->player_x--;
		ft_printf("Moves: %d\n", g_game->moves);
	}
	ft_printf("Left key Pressed!\n");
}

void	move_up(void)
{
	if (!is_wall(g_game->player_x, g_game->player_y - 1))
	{
		g_game->moves++;
		g_game->player_y--;
		ft_printf("Moves: %d\n", g_game->moves);
	}
	ft_printf("Up key Pressed!\n");
}

void	move_down(void)
{
	if (!is_wall(g_game->player_x, g_game->player_y + 1))
	{
		g_game->moves++;
		g_game->player_y++;
		ft_printf("Moves: %d\n", g_game->moves);
	}
	ft_printf("Down key Pressed!\n");
}
