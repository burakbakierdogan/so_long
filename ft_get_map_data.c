/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:13:16 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/26 12:39:31 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	ft_get_row_nbr(char **map_src)
{
	int	i;

	i = 0;
	while (map_src[i])
		i++;
	return (i);
}

static	void	ft_get_wall_locations(t_map *map, char **map_src, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_src[y])
	{
		while (map_src[y][x])
		{
			if (map_src[y][x] == c)
			{
				map -> wall[map -> wall_nbr][0][0] = 64 * x;
				map -> wall[map -> wall_nbr][0][1] = 64 * y;
				map -> wall_nbr++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

static	void	ft_get_space_locations(t_map *map, char **map_src, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_src[y])
	{
		while (map_src[y][x])
		{
			if (map_src[y][x] == c)
			{
				map -> space[map -> space_nbr][0][0] = 64 * x;
				map -> space[map -> space_nbr][0][1] = 64 * y;
				map -> space_nbr += 1;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_get_map_data(t_map *map, char **map_src)
{
	map -> res[0] = ft_strlen_nl (map_src[0]);
	map -> res[1] = ft_get_row_nbr(map_src);
	map -> wall_nbr = 0;
	map -> collectible_nbr = 0;
	map -> space_nbr = 0;
	map -> collectible_status = 0;
	map -> move = 0;
	map -> ex_status = 1;
	ft_get_wall_locations(map, map_src, '1');
	ft_get_space_locations(map, map_src, '0');
	ft_get_collectible_locations(map, map_src, 'C');
	ft_get_exit_location(map, map_src, 'E');
	ft_get_player_location(map, map_src, 'P');
	ft_free_map_src(map_src);
}
