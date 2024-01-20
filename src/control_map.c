/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:12:43 by ekoubbi           #+#    #+#             */
/*   Updated: 2024/01/15 19:05:50 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	is_possible(t_game game)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc((game.map_height + 1) * sizeof(char *));
	while (game.map[i])
	{
		tab[i] = malloc(game.map_width + 1);
		j = 0;
		while (game.map[i][j])
		{
			tab[i][j] = game.map[i][j];
			j++;
		}
		tab[i][j] = 0;
		i++;
	}
	tab[i] = NULL;
	fill(tab, game.x_player, game.y_player);
	i = scan_tab(tab);
	if (i)
		return (1);
	return (0);
}

int	scan_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != 'F' && tab[i][j] != '1' && tab[i][j] != '0')
			{
				free_tab(tab);
				return (1);
			}
			j++;
		}
		i++;
	}
	free_tab(tab);
	return (0);
}

void	fill(char **tab, int x, int y)
{
	if (tab[y][x] == '1' || tab[y][x] == 'F')
		return ;
	tab[y][x] = 'F';
	fill(tab, x, y + 1);
	fill(tab, x + 1, y);
	fill(tab, x, y - 1);
	fill(tab, x - 1, y);
}
*/
int	is_not_close(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (game->map[0][++i])
	{
		if (game->map[0][i] != '1' && game->map[0][i] != 'E')
			j = 0;
		if (game->map[game->map_height - 1][i] != '1'
				&& game->map[game->map_height - 1][i] != 'E')
			j = 0;
	}
	i = (game->map_height - 1);
	while (i >= 0)
	{
		if (game->map[i][0] != '1'
				&& game->map[i][0] != 'E')
			j = 0;
		if (game->map[i][game->map_width - 1] != '1'
				&& game->map[i][game->map_width - 1] != 'E')
			j = 0;
		i--;
	}
	return (j);
}

int	is_not_rectangle(t_game *game)
{
	int	i;

	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	control_char(t_game *game)
{
	int		i;
	int		j;
	char	**s;
	int		z;

	i = 0;
	z = 1;
	s = game->map;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != '0' && s[i][j] != '1' && s[i][j] && s[i][j] != 'C'
					&& s[i][j] != 'E' && s[i][j] != 'P')
				z = 0;
			j++;
		}
		i++;
	}
	return (z);
}

int	control_name(t_game *game)
{
	int	i;

	i = -1;
	while (game->file_name[++i])
	{
		if (game->file_name[i] == '.')
		{
			i++;
			if (game->file_name[i] == 'b')
			{
				i++;
				if (game->file_name[i] == 'e')
				{
					i++;
					if (game->file_name[i] == 'r')
					{
						i++;
						if (game->file_name[i] == '\0')
							return (1);
					}
				}
			}
		}
	}
	return (0);
}

void	player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->x_player = x;
				game->y_player = y;
			}
			x++;
		}
		y++;
	}
}
