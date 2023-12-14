/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:59:20 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/12/14 02:01:13 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../minilibx/mlx42.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>

# define WIDTH 512
# define HEIGHT 512

typedef struct s_texture
{
	mlx_texture_t	*player;
	mlx_image_t		*img_player;
	mlx_texture_t	*item;
	mlx_image_t		*img_item;
	mlx_texture_t	*exit;
	mlx_image_t		*img_exit;
	mlx_texture_t	*wall;
	mlx_image_t		*img_wall;
	mlx_texture_t	*ground;
	mlx_image_t		*img_ground;

}		t_texture;

typedef struct game
{
	int			exit;
	int			item;
	int			player;
	int			fd;
	char		*file_name;
	char		**map;
	int			map_height;
	int			map_width;
	int			control; 
	int			x_player;
	int			y_player;
	mlx_t		*mlx;
	t_texture	img;
	
}	t_game;

typedef	struct s_player
{
	int	x;	
	int	y;

}		s_player;

void	init_game(char **argv, t_game *game);
void	read_map(t_game *game);
void	scan_map(t_game *game);
int		is_not_close(t_game *game);
int		is_not_rectangle(t_game *game);
int		control_char(t_game *game);
int		control_name(t_game *game);
char	*check_error(t_game *game);
void	free_error(t_game *game);
void	ft_hook(void *param);
void	player_pos(t_game *game);
void	start_game(t_game *game);
void	texture(t_game *game);
bool	mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param);

#endif
