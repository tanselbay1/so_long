/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:53:06 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/18 14:37:36 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	is_in_list(int x, int y, t_tile *grass_list)
{
	t_tile	*ptr;

	ptr = grass_list;
	if (!ptr)
		return (0);
	while (ptr)
	{
		if (ptr->x == x && ptr->y == y)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

t_tile	*find_tile_in_list(int x, int y, t_tile *list)
{
	t_tile	*ptr;

	ptr = list;
	if (!ptr)
		return (0);
	while (ptr)
	{
		if (ptr->x == x && ptr->y == y)
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}

static int	is_p_c_e_in_one_map(t_game *game)
{
	t_player	*player;
	int			p;
	int			f;
	int			h;
	t_tile		*chestlist_ptr;

	game->grass_list = malloc(sizeof(t_tile));
	game->grass_list->x = 0;
	game->grass_list->y = 0;
	game->grass_list->next = 0;
	player = game->player;
	flood_fill(player->x, player->y, game);
	p = is_in_list(player->x, player->y, game->grass_list);
	chestlist_ptr = game->chest_list;
	while (chestlist_ptr)
	{
		f = is_in_list(chestlist_ptr->x, chestlist_ptr->y, game->grass_list);
		chestlist_ptr = chestlist_ptr->next;
	}
	h = is_in_list(game->exit->x, game->exit->y, game->grass_list);
	if (p + f + h != 3)
		ft_error("Error\nPlayer, Chest, Exit should be connected on the map!");
	return (0);
}

void	error_check(t_game *game)
{
	is_p_c_e_in_one_map(game);
	if (game->player_cnt * game->exit_cnt != 1 || game->chest_cnt < 1)
		ft_error("Error\n1 Player, 1 Chest, 1 Exit must be on the map!");
}
