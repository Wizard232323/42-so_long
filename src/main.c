/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:51:22 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/12/14 03:12:39 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(char **argv, t_game *game)
{
	game->exit = 0;
	game->item = 0;
	game->player = 0;
	game->map = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->x_player = 0;
	game->y_player = 0;
	game->file_name = ft_strdup(argv[1]);
}

void	read_map(t_game *game)
{
	char	temp_map[1000000];
	int		n; 

	n = read(game->fd, temp_map, 1000000);
	temp_map[n] = 0;
	game->map = ft_split(temp_map, '\n');
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

char	*check_error(t_game *game)
{
	if (game->map_height <= 2)
		return ("Map need to have minimum three lines.\n");
	if (game->exit != 1)
		return ("Map need to have only one Exit.\n");
	if (game->item < 1)
		return ("Map need to contain minimum one item.\n");
	if (!is_not_rectangle(game))
		return ("Map need to be rectangle.\n");
	if (!is_not_close(game))
		return ("Map need to be close.\n");
	if (!control_char(game))
		return ("Map file can use only : 1 - 0 - C - P or E.\n");
	if (!control_name(game))
		return ("Map file must to be a *.ber.");
	return (0);
}

void free_error(t_game *game)
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
}

void ft_hook(void *param)
{
	t_game	*game;

	game = param;

//    image->instances[0].z = 1;                                // profondeur
//	if (mlx_is_key_down(game->mlx, MLX_KEY_0))
//			image2->instances[0].z = image->instances[0].z - 1;
//	if (mlx_is_key_down(game->mlx, MLX_KEY_1))
  //      image2->instances[0].z = image->instances[0].z + 1;    

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))                 // mvt player 1
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->img.img_player->instances[0].y -=10;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->img.img_player->instances[0].y += 10;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->img.img_player->instances[0].x -= 10;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->img.img_player->instances[0].x += 10;


}

void	player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->y_player = (i * 32); 
				game->x_player = (j * 32);
			}
			j++;
		}
		i++;
	}
	ft_printf("player x : %d\n player y : %d", game->x_player, game->y_player);
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
			mlx_image_to_window(game->mlx, game->img.img_ground, x * 32, y * 32);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img.img_exit, x * 32, y * 32);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img.img_item, x * 32, y * 32);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img.img_wall, x * 32, y * 32); 
		}
	}

}

void	start_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width * 32 , game->map_height * 32, game->file_name, true);
	if(!game->mlx)
		return;
	player_pos(game);
	texture(game);
	create_map(game);
	
	mlx_image_to_window(game->mlx, game->img.img_player, 0, 0);
	game->img.img_player->instances[0].y = game->y_player;
	game->img.img_player->instances[0].x = game->x_player;
	ft_printf("player x : %d\n player y : %d", game->x_player, game->y_player);	
	mlx_loop_hook(game->mlx , ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
void	texture(t_game *game)
{
game->img.player = mlx_load_png("img/player.png");
game->img.img_player = mlx_texture_to_image(game->mlx, game->img.player);
game->img.exit = mlx_load_png("img/exit.png");
game->img.img_exit = mlx_texture_to_image(game->mlx, game->img.exit);
game->img.ground = mlx_load_png("img/ground.png");
game->img.img_ground = mlx_texture_to_image(game->mlx, game->img.ground);
game->img.item = mlx_load_png("img/coin.png");
game->img.img_item = mlx_texture_to_image(game->mlx, game->img.item);
game->img.wall = mlx_load_png("img/wall.png");
game->img.img_wall = mlx_texture_to_image(game->mlx, game->img.wall);
}


int	main(int argc, char *argv[])
{
	t_game	game;
	char	*error;

	if (argc != 2)
	{
		ft_printf("Argument error.\n");
		return (1);
	}
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd <= 0)
	{
		ft_printf("File read error.\n");
		return (1);
	}
	init_game(argv, &game);
	read_map(&game);
	scan_map(&game);
	error = check_error(&game);
	if (error != 0)
	{
		free_error(&game);
		ft_printf("%s\n", error);
		return (EXIT_FAILURE);
	}
	start_game(&game);
	return (EXIT_SUCCESS);
}

