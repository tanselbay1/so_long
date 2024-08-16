/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:48:35 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/16 11:18:26 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "MLX42.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# define PATH_GRASS "Assets/Grass_Middle.png"
# define PATH_WATER "Assets/Tiles.png"
# define PATH_SHIBA "./asset_pack/Envitonment/GreenWoods/Assets/Trees.png"
# define PATH_HOUSE "./asset_pack/Envitonment/GreenWoods/Assets/Tiles.png"
# define PATH_FOOD "./asset_pack/Envitonment/GreenWoods/Assets/Tiles.png"
# define TILE_SIZE 128


// so_long.c
void	ft_error(char *str);

#endif