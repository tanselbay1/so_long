/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:47:28 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/18 14:37:43 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	move(t_game *game, int next_x, int next_y)
{
	t_player	*player;
	t_tile		*map;
	mlx_t		*mlx;
	t_tile		*chest;

	player = game->player;
	map = game->map;
	mlx = game->mlx;
	if (!(iswall(map, next_x, next_y)))
	{
		img_to_window(mlx, game->player_png, player->x, player->y);
		if (player->collect_cnt == game->chest_cnt)
			img_to_window(mlx, game->chest_png, player->x, player->y);
		ft_printf("%d\n", player->movements + 1);
		(player->movements)++;
	}
	chest = find_tile_in_list(next_x, next_y, game->chest_list);
	if (chest && chest->visited == 0)
	{
		game->player->collect_cnt++;
		chest->visited = 1;
	}
}

void	move_up(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_object	*exit;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	exit = game->exit;
	mlx = game->mlx;
	if (!(iswall(map, player->x, player->y - TILE_SIZE)))
	{
		player->y -= TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x, player->y + TILE_SIZE);
		if (exit->x == player->x && exit->y == player->y + TILE_SIZE)
			img_to_window(mlx, game->exit_png, player->x, player->y
				+ TILE_SIZE);
	}
}

void	move_down(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_object	*exit;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	exit = game->exit;
	mlx = game->mlx;
	if (!(iswall(map, player->x, player->y + TILE_SIZE)))
	{
		player->y += TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x, player->y - TILE_SIZE);
		if (exit->x == player->x && exit->y == player->y - TILE_SIZE)
			img_to_window(mlx, game->exit_png, player->x, player->y
				- TILE_SIZE);
	}
}

void	move_left(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_object	*exit;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	exit = game->exit;
	mlx = game->mlx;
	if (!(iswall(map, player->x - TILE_SIZE, player->y)))
	{
		player->x -= TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x + TILE_SIZE, player->y);
		if (exit->x == player->x + TILE_SIZE && exit->y == player->y)
			img_to_window(mlx, game->exit_png, player->x + TILE_SIZE,
				player->y);
	}
}

void	move_right(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_object	*exit;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	exit = game->exit;
	mlx = game->mlx;
	if (!(iswall(map, player->x + TILE_SIZE, player->y)))
	{
		player->x += TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x - TILE_SIZE, player->y);
		if (exit->x == player->x - TILE_SIZE && exit->y == player->y)
			img_to_window(mlx, game->exit_png, player->x - TILE_SIZE,
				player->y);
	}
}
