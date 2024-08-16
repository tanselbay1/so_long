/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:46:11 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/16 11:18:47 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../MLX42/include/MLX42/MLX42.h"
#include "../MLX42/include/MLX42/MLX42_Int.h"
#include "../headers/so_long.h"
#define WIDTH 256
#define HEIGHT 256

// Exit the program as failure.
void ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "myBalls", true);
	if (!mlx)
		ft_error("test");

	/* Do stuff */

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png(PATH_GRASS);
	if(!texture)
		ft_error("test");
	// Convert texture to a displayable image
	mlx_image_t* img1 = mlx_texture_to_image(mlx, texture);
	if(!img1)
		ft_error("test");
	if (mlx_image_to_window(mlx, img1, 0, 0) < 0)
		ft_error("test");

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error("test");

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);

	// Remove images and clean texture
	mlx_delete_image(mlx, img1);
	mlx_delete_texture(texture);

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}