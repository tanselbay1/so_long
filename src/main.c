/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:46:11 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/21 16:03:00 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

int	iswall(t_tile *map, int x, int y)
{
	t_tile	*tile;

	tile = map;
	if (!tile)
		return (-1);
	while (tile)
	{
		if (tile->x == x && tile->y == y)
		{
			if (tile->type == 1)
				return (1);
			else
				return (0);
		}
		tile = tile->next;
	}
	return (0);
}

static void	get_map_size(char **argv, t_game *game)
{
	char	*gnl;
	int		len;
	int		src;
	int		height;

	height = 0;
	src = open(argv[1], O_RDONLY);
	gnl = get_next_line(src);
	if (!gnl)
	{
		free(gnl);
		ft_error("Error\nCannot read the map");
	}
	len = ft_strlen(gnl);
	game->width = len - 1;
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(src);
		height++;
	}
	game->height = height;
}

static void	if_not_game(t_game *game)
{
	if (!game)
	{
		free(game);
		ft_error("Error\nCannot initialize a game");
	}
}

int32_t	main(int argc, char **argv)
{
	mlx_t	*mlx;
	int		src;
	t_game	*game;

	if (argc != 2)
		return (-1);
	if (!is_ber_extension(argv[1]))
		ft_error("Error\nFile extention is not .ber");
	game = malloc(sizeof(t_game));
	if_not_game(game);
	game = game_init(game);
	load_pngs(game);
	get_map_size(argv, game);
	src = open(argv[1], O_RDONLY);
	mlx = mlx_init(64 * game->width, 64 * game->height, "Test", false);
	if (!mlx)
		ft_error("Error\nCannot initialize a map");
	else
		game->mlx = mlx;
	draw_ber(src, game);
	error_check(game);
	mlx_hooks(game);
	clear_memory(game);
	close(src);
	return (EXIT_SUCCESS);
}
