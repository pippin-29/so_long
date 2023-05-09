/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:43:06 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/07 09:16:37 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"
#include <fcntl.h>

extern t_game	*g_game;

int	map_check_valid_char(char **grid)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (grid[i])
	{
		while (grid[i][j])
		{
			if (grid[i][j] != '1' && grid[i][j] != '0' && grid[i][j] != 'C'
				&& grid[i][j] != 'P' && grid[i][j] != 'E')
			{
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	map_check_shape(char **grid)
{
	size_t	first_line;
	int		i;

	i = 1;
	first_line = ft_strlen(grid[0]);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != first_line)
			return (0);
		i++;
	}
	return (1);
}

void	parse_map(char *filename)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error: Failed to open file");
		exit(1);
	}
	line = get_next_line(fd);
	parse_map_while_loop(fd, line, &i);
	g_game->grid[i] = NULL;
	close(fd);
}

int	map_check_walls(void)
{
	int	i;

	i = 0;
	while (i < g_game->grid_width)
		if (g_game->grid[0][i++] != '1')
			return (-1);
	i = 0;
	while (i < g_game->grid_width)
		if (g_game->grid[g_game->grid_height - 1][i++] != '1')
			return (-1);
	i = 0;
	while (i < g_game->grid_height)
		if (g_game->grid[i++][0] != '1')
			return (-1);
	i = 0;
	while (i < g_game->grid_height)
		if (g_game->grid[i++][g_game->grid_width - 1] != '1')
			return (-1);
	return (0);
}

void	parse_map_while_loop(int fd, char *line, int *i)
{
	while ((line != NULL))
	{
		g_game->grid_width = ft_strlen(line);
		if (ft_strchr(line, '\n'))
			g_game->grid[(*i)] = ft_strndup(line, g_game->grid_width - 1);
		else
			g_game->grid[(*i)] = ft_strndup(line, g_game->grid_width);
		g_game->grid_height++;
		free(line);
		line = get_next_line(fd);
		(*i)++;
	}
}
