/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:49:34 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/18 14:51:51 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	add_object(t_game *game, int x, int y, char c)
{
	t_tile	*chest_list;

	chest_list = game->chest_list;
	if (c == 'P')
	{
		img_to_window(game->mlx, game->player_png, x, y);
		game->player->x = x;
		game->player->y = y;
		game->player_cnt++;
	}
	else if (c == 'C')
	{
		img_to_window(game->mlx, game->chest_png, x + 20, y + 25);
		ft_map_lstadd_back(&chest_list, ft_map_lstnew(c, x, y));
		game->chest_list->x = x;
		game->chest_list->y = y;
		game->chest_cnt++;
	}
	else if (c == 'E')
	{
		img_to_window(game->mlx, game->exit_png, x, y);
		game->exit->x = x;
		game->exit->y = y;
		game->exit_cnt++;
	}
}

void	render_tile(t_game *game, char c, int x, int y)
{
	if (c == '1')
		img_to_window(game->mlx, game->tree_png, x, y);
	else
	{
		img_to_window(game->mlx, game->grass_png, x, y);
		add_object(game, x, y, c);
	}
}

void	render_and_list(char c, t_game *game, int next_x, int next_y)
{
	tile_to_map_list(c, &game->map, next_x, next_y);
	render_tile(game, c, next_x, next_y);
}

void	load_pngs(t_game *game)
{
	game->player_png = mlx_load_png(PATH_ARCHER);
	game->chest_png = mlx_load_png(PATH_CHEST);
	game->exit_png = mlx_load_png(PATH_EXIT);
	game->grass_png = mlx_load_png(PATH_GRASS);
	game->tree_png = mlx_load_png(PATH_TREE);
}
