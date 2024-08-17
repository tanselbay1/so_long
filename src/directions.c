/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:47:28 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/17 10:47:46 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	move(t_game *game, int next_x, int next_y)
{
	t_player	*player;
	t_tile		*map;
	t_object	*house;
	mlx_t		*mlx;
	t_tile		*food;

	player = game->player;
	map = game->map;
	house = game->house;
	mlx = game->mlx;
	if (!(iswall(map, next_x, next_y)))
	{
		img_to_window(mlx, game->player_png, player->x, player->y);
		if (player->collect_cnt == game->food_cnt)
			img_to_window(mlx, game->food_png, player->x, player->y);
		ft_printf("%d\n", player->movements + 1);
		(player->movements)++;
	}
	food = find_tile_in_list(next_x, next_y, game->food_list);
	if (food && food->visited == 0)
	{
		game->player->collect_cnt++;
		food->visited = 1;
	}
}

void	move_up(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_object	*house;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	house = game->house;
	mlx = game->mlx;
	if (!(iswall(map, player->x, player->y - TILE_SIZE)))
	{
		player->y -= TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x, player->y + TILE_SIZE);
		if (house->x == player->x && house->y == player->y + TILE_SIZE)
			img_to_window(mlx, game->house_png,
				player->x, player->y + TILE_SIZE);
	}
}

void	move_down(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_object	*house;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	house = game->house;
	mlx = game->mlx;
	if (!(iswall(map, player->x, player->y + TILE_SIZE)))
	{
		player->y += TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x, player->y - TILE_SIZE);
		if (house->x == player->x && house->y == player->y - TILE_SIZE)
			img_to_window(mlx, game->house_png,
				player->x, player->y - TILE_SIZE);
	}
}

void	move_left(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_object	*house;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	house = game->house;
	mlx = game->mlx;
	if (!(iswall(map, player->x - TILE_SIZE, player->y)))
	{
		player->x -= TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x + TILE_SIZE, player->y);
		if (house->x == player->x + TILE_SIZE && house->y == player->y)
			img_to_window(mlx, game->house_png,
				player->x + TILE_SIZE, player->y);
	}
}

void	move_right(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_object	*house;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	house = game->house;
	mlx = game->mlx;
	if (!(iswall(map, player->x + TILE_SIZE, player->y)))
	{
		player->x += TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x - TILE_SIZE, player->y);
		if (house->x == player->x - TILE_SIZE && house->y == player->y)
			img_to_window(mlx, game->house_png,
				player->x - TILE_SIZE, player->y);
	}
}