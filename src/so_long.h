/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:59:20 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/29 23:13:34 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../minilibx/mlx42.h"
# include "../libft/libft.h"

# define WIDTH 512
# define HEIGHT 512

typedef struct s_texture
{
	mlx_texture_t	*player;
    mlx_texture_t   *player2;
	mlx_image_t		*img_player;
	
}		t_texture;

#endif
