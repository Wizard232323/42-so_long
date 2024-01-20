/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:02:31 by ekoubbi           #+#    #+#             */
/*   Updated: 2024/01/15 17:45:15 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	eat_item(t_game *game)
{
	ft_printf("Nombre de pas : %d\n", game->move);
	if (game->map[((game->y_player))][game->x_player] == 'C')
	{
		game->check.item += 1;
		game->map[game->y_player][game->x_player] = '0';
		mlx_image_to_window(game->mlx,
			game->img.img_ground, game->x_player * 32, game->y_player * 32);
		game->img.img_ground->instances[game->img.img_ground->count - 1]
			.z = (game->img.img_player->instances[0].z - 1);
	}
	if (game->map[game->y_player][game->x_player]
		== 'E' && game->check.exit == 1)
	{
		ft_printf(" YOU WIN !\n");
		mlx_close_window(game->mlx);
	}
}

void	up(t_game *game)
{
	if (game->map[((game->y_player) - 1)][game->x_player] == '1')
		return ;
	game->img.img_player->instances[0].y -= 32;
	game->y_player -= 1;
	game->move += 1;
	if (game->item == game->check.item)
		game->check.exit = 1;
	eat_item(game);
}

void	down(t_game *game)
{
	if (game->map[game->y_player + 1][game->x_player] == '1')
		return ;
	game->img.img_player->instances[0].y += 32;
	game->y_player += 1;
	game->move += 1;
	if (game->item == game->check.item)
		game->check.exit = 1;
	eat_item(game);
}

void	left(t_game *game)
{
	if (game->map[game->y_player][game->x_player - 1] == '1')
		return ;
	game->img.img_player->instances[0].x -= 32;
	game->x_player -= 1;
	game->move += 1;
	if (game->item == game->check.item)
		game->check.exit = 1;
	eat_item(game);
}

void	right(t_game *game)
{
	if (game->map[game->y_player][game->x_player + 1] == '1')
		return ;
	game->img.img_player->instances[0].x += 32;
	game->x_player += 1;
	game->move += 1;
	if (game->item == game->check.item)
		game->check.exit = 1;
	eat_item(game);
}
