/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx42_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:43:56 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/21 16:10:22 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

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
		clear_memory(game);
		exit(0);
	}
}

static void	finish_game(void *param)
{
	t_game		*game;
	t_player	*player;
	t_object	*final_exit;

	game = param;
	player = game->player;
	final_exit = game->exit;
	if (player->x == final_exit->x && player->y == final_exit->y)
	{
		if (player->collect_cnt >= game->chest_cnt)
		{
			ft_printf("ARCHER ESCAPED THE FOREST!");
			clear_memory(param);
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

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

bool	is_ber_extension(const char *filename)
{
	const char	*dot = ft_strrchr(filename, '.');

	if (!dot || dot == filename)
		return (false);
	return (ft_strcmp(dot, ".ber") == 0);
}
