/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:51:22 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/30 00:21:31 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t  *image;
static mlx_image_t  *image2;
static mlx_image_t  *image3;

void ft_hook(void* param)
{
	mlx_t* mlx = param;

    image->instances[0].z = 1;                                // profondeur
	if (mlx_is_key_down(mlx, MLX_KEY_0))
        image2->instances[0].z = image->instances[0].z - 1;
    if (mlx_is_key_down(mlx, MLX_KEY_1))
        image2->instances[0].z = image->instances[0].z + 1;    

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))                 // mvt player 1
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 10;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 10;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 10;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 10;

    if (mlx_is_key_down(mlx, MLX_KEY_W))                      // mvt player 2
        image2->instances[0].y -= 8;
    if (mlx_is_key_down(mlx, MLX_KEY_S)) 
     	image2->instances[0].y += 8;
    if (mlx_is_key_down(mlx, MLX_KEY_A))
		image2->instances[0].x -= 8;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		image2->instances[0].x += 8;
}

// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t* mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);                 // defini la fenetre
	
    mlx_texture_t* texture = mlx_load_png("./img/player.png");    // download l image
	image = mlx_texture_to_image(mlx, texture);					 // transforme en texture 								
    mlx_image_to_window(mlx, image, 50, 50);					// pose la texture sur la map

    mlx_texture_t* texture2 = mlx_load_png("./img/player2.png");
    image2 = mlx_texture_to_image(mlx, texture2);
    mlx_image_to_window(mlx, image2, 400, 400);


	mlx_loop_hook(mlx, ft_hook, mlx);                           
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
