/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx42_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:43:56 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/17 10:44:13 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("GAME SHUT DOWN!");
		exit(0);
	}
}

static void	finish_game(void *param)
{
	t_game		*game;
	t_player	*player;
	t_object	*house;

	game = param;
	player = game->player;
	house = game->house;
	if (player->x == house->x && player->y == house->y)
	{
		if (player->collect_cnt >= game->food_cnt)
		{
			ft_printf("SHIBA ESCAPED WITH THE FOOD!");
			exit(0);
		}
	}
}

void	mlx_hooks(t_game *game)
{
	mlx_t	*mlx;

	mlx = game->mlx;
	mlx_key_hook(mlx, &my_keyhook, game);
	mlx_loop_hook(mlx, &finish_game, game);
	mlx_loop(mlx);
}