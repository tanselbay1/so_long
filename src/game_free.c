/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:53:43 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/20 14:05:56 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_list(t_tile *head)
{
	t_tile	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	clear_memory(t_game *map_data)
{
	free(map_data->map);
	mlx_delete_texture(map_data->tree_png);
	mlx_delete_texture(map_data->player_png);
	mlx_delete_texture(map_data->exit_png);
	mlx_delete_texture(map_data->grass_png);
	mlx_delete_texture(map_data->chest_png);
	mlx_terminate(map_data->mlx);
}
