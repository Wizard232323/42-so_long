/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:49:59 by ekoubbi           #+#    #+#             */
/*   Updated: 2024/01/15 17:43:13 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_error(t_game *game, int free_texture)
{
	int	i;

	i = 0;
	free(game->file_name);
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	if (free_texture)
	{
		mlx_delete_texture(game->img.item);
		mlx_delete_texture(game->img.player);
		mlx_delete_texture(game->img.exit);
		mlx_delete_texture(game->img.wall);
		mlx_delete_texture(game->img.ground);
	}
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
