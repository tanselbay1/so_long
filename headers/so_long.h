/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:48:35 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/18 14:41:27 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define PATH_GRASS "Assets/green_texture.png"
# define PATH_TREE "Assets/Oak_Tree.png"
# define PATH_ARCHER "Assets/archer.png"
# define PATH_EXIT "Assets/FarmLand_Tile.png"
# define PATH_CHEST "Assets/Chest.png"
# define TILE_SIZE 64

typedef struct s_player
{
	int				x;
	int				y;
	int				movements;
	int				collect_cnt;
}					t_player;

enum				e_tiletype
{
	WALL,
	GRASS
};

typedef struct s_tile
{
	enum e_tiletype	type;
	int				visited;
	int				x;
	int				y;
	struct s_tile	*next;
}					t_tile;

typedef struct s_object
{
	int				x;
	int				y;
}					t_object;

typedef struct s_objectlist
{
	int				x;
	int				y;
	struct s_tree	*next;
}					t_objectlist;

typedef struct s_game
{
	mlx_t			*mlx;
	t_player		*player;
	t_tile			*map;
	t_object		*chest;
	t_objectlist	*grass;
	t_objectlist	*tree;
	t_object		*exit;
	t_tile			*grass_list;
	t_tile			*chest_list;
	int				player_cnt;
	int				chest_cnt;
	int				exit_cnt;
	int				width;
	int				height;
	mlx_texture_t	*player_png;
	mlx_texture_t	*chest_png;
	mlx_texture_t	*exit_png;
	mlx_texture_t	*grass_png;
	mlx_texture_t	*tree_png;

}					t_game;

// SO_LONG.C
void				ft_error(char *str);
int					iswall(t_tile *map, int x, int y);

// GAME_INIT.C
t_game				*game_init(t_game *game);

// RENDER.C
void				add_object(t_game *game, int x, int y, char c);
void				render_tile(t_game *game, char c, int x, int y);
void				render_and_list(char c, t_game *game, int next_x,
						int next_y);
void				load_pngs(t_game *game);

// MAP_DRAW.C
int					if_first_gnl_ok(char *gnl);
char				*first_gnl(int src);
void				map_to_window(char *gnl, t_game *game, int src, int len);
void				draw_ber(int src, t_game *game);

// MAP_UTILS.C
t_tile				*ft_map_lstnew(char c, int x, int y);
void				ft_map_lstadd_back(t_tile **lst, t_tile *new);
t_tile				*ft_map_lstlast(t_tile *lst);
void				tile_to_map_list(char c, t_tile **list, int x, int y);
int					img_to_window(mlx_t *mlx, mlx_texture_t *png, int x, int y);

// DIRECTIONS.C
void				move_up(t_game *game);
void				move_down(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);

// MAP_VERIFY.C
int					northest_wall_check(char *str, int len);
char				*map_verify_and_gnl(int src, int len);

// TILE_CHECK.C
void				flood_fill(int x, int y, t_game *game);

// CHECK_ERROR.C
int					is_in_list(int x, int y, t_tile *grass_list);
t_tile				*find_tile_in_list(int x, int y, t_tile *list);
void				error_check(t_game *game);

// MLX42_HOOKS.C
void				mlx_hooks(t_game *game);

#endif