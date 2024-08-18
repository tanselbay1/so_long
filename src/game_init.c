/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:08:58 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/18 14:39:26 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	player_init(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_error("Error\n error allocating memory for game");
	game->player_cnt = 0;
	game->player->movements = 0;
	game->player->collect_cnt = 0;
}

static void	object_init(t_game *game)
{
	game->chest = malloc(sizeof(t_object));
	if (!game->chest)
		ft_error("Error\n error allocating memory for game");
	game->exit = malloc(sizeof(t_object));
	if (!game->exit)
		ft_error("Error\n error allocating memory for game");
}

static void	objectlist_init(t_game *game)
{
	game->tree = malloc(sizeof(t_objectlist));
	if (!game->tree)
		ft_error("Error\n error allocating memory for game");
	game->grass = malloc(sizeof(t_objectlist));
	if (!game->grass)
		ft_error("Error\n error allocating memory for game");
}

static void	chestlist_init(t_game *game)
{
	game->chest_list = malloc(sizeof(t_tile));
	if (!game->chest_list)
		ft_error("Error\n error allocating memory for game");
	game->chest_list->visited = 0;
	game->chest_list->x = 0;
	game->chest_list->y = 0;
	game->chest_list->next = 0;
}

t_game	*game_init(t_game *game)
{
	player_init(game);
	object_init(game);
	objectlist_init(game);
	chestlist_init(game);
	game->chest_cnt = 0;
	game->exit_cnt = 0;
	game->width = 1;
	game->height = 1;
	return (game);
}
