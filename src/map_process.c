/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:22:06 by ekoubbi           #+#    #+#             */
/*   Updated: 2024/01/17 17:10:17 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	char	temp_map[1000000];
	int		n;

	n = read(game->fd, temp_map, 1000000);
	temp_map[n] = 0;
	game->map = ft_split(temp_map, '\n');
	player_pos(game);
	scan_map(game);
}

void	scan_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->item += 1;
			if (game->map[i][j] == 'E')
				game->exit += 1;
			if (game->map[i][j] == 'P')
				game->player += 1;
			j++;
		}
		i++;
	}
	game->map_height = i;
	game->map_width = ft_strlen(game->map[0]);
}

void	texture(t_game *game)
{
	game->img.player = mlx_load_png("img/White_Rabbit.png");
	game->img.img_player = mlx_texture_to_image(game->mlx, game->img.player);
	game->img.exit = mlx_load_png("img/Rabbit_Hole.png");
	game->img.img_exit = mlx_texture_to_image(game->mlx, game->img.exit);
	game->img.ground = mlx_load_png("img/Grass.png");
	game->img.img_ground = mlx_texture_to_image(game->mlx, game->img.ground);
	game->img.item = mlx_load_png("img/Carot_green.png");
	game->img.img_item = mlx_texture_to_image(game->mlx, game->img.item);
	game->img.wall = mlx_load_png("img/Three.png");
	game->img.img_wall = mlx_texture_to_image(game->mlx, game->img.wall);
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		right(game);
}

void	create_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			mlx_image_to_window(game->mlx,
				game->img.img_ground, x * 32, y * 32);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx,
					game->img.img_exit, x * 32, y * 32);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx,
					game->img.img_item, x * 32, y * 32);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx,
					game->img.img_wall, x * 32, y * 32);
		}
	}
	mlx_image_to_window(game->mlx, game->img.img_player,
		game->x_player * 32, game->y_player * 32);
}
