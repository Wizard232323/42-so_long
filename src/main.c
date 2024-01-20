/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:51:22 by ekoubbi           #+#    #+#             */
/*   Updated: 2024/01/15 19:02:05 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int	false_path(t_game *game)
{
	


}*/

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
	game->move = 0;
	game->exit = 0;
	game->check.item = 0;
	game->check.exit = 0;
	game->check.checked = 0;
}

char	*check_error(t_game *game)
{
	if (game->map_height <= 2)
		return ("Map needs to have minimum three lines.\n");
	if (game->exit != 1)
		return ("Map needs to have only one Exit.\n");
	if (game->item < 1)
		return ("Map needs to contain minimum one item.\n");
	if (!is_not_rectangle(game))
		return ("Map needs to be rectangle.\n");
	if (!is_not_close(game))
		return ("Map needs to be close.\n");
	if (!control_char(game))
		return ("Map file can only use : 1 - 0 - C - P or E.\n");
	if (!control_name(game))
		return ("Map file must to be a *.ber.\n");
	if (game->player != 1)
		return ("Map needs to contain only one Player.\n");
	if (is_possible(*game))
		return ("Map without solution.\n");
	return (0);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width * 32,
			game->map_height * 32, game->file_name, true);
	if (!game->mlx)
		return ;
	player_pos(game);
	texture(game);
	create_map(game);
	mlx_key_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	free_error(game, 1);
	mlx_terminate(game->mlx);
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
	error = check_error(&game);
	if (error != 0)
	{
		free_error(&game, 0);
		ft_printf("%s\n", error);
		return (EXIT_FAILURE);
	}
	start_game(&game);
	return (EXIT_SUCCESS);
}
