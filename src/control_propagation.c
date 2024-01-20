/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_propagation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:02:36 by ekoubbi           #+#    #+#             */
/*   Updated: 2024/01/17 17:18:30 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
