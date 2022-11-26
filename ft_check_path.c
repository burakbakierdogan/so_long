/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:36:19 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/26 07:19:57 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_moveright(t_map *map, int x, int y)
{
	int	i;

	map -> wall_nbr += 1;
	map -> wall[map -> wall_nbr][0][0] = x + 64;
	map -> wall[map -> wall_nbr][0][1] = y;
	if (ft_compare_locations(x + 64, y,
		map -> collectible, map -> collectible_nbr) != -1)
	{
		i = ft_compare_locations(x + 64, y,
			map -> collectible, map -> collectible_nbr);
		map -> collectible[i][0][0] = -42;
		map -> collectible[i][0][1] = -42;
		map -> collectible_status++;
	}
	if (x + 64 == map -> ex[0] && y == map -> ex[1])
		map -> ex_status = 0;
}

static	void	ft_moveleft(t_map *map, int x, int y)
{
	int	i;

	map -> wall_nbr += 1;
	map -> wall[map -> wall_nbr][0][0] = x -64;
	map -> wall[map -> wall_nbr][0][1] = y;
	if (ft_compare_locations(x - 64, y,
		map -> collectible, map -> collectible_nbr) != -1)
	{
		i = ft_compare_locations(x - 64, y,
			map -> collectible, map -> collectible_nbr);
		map -> collectible[i][0][0] = -42;
		map -> collectible[i][0][1] = -42;
		map -> collectible_status++;
	}
	if (x - 64 == map -> ex[0] && y == map -> ex[1])
		map -> ex_status = 0;
}

static	void	ft_moveup(t_map *map, int x, int y)
{
	int	i;

	map -> wall_nbr += 1;
	map -> wall[map -> wall_nbr][0][0] = x;
	map -> wall[map -> wall_nbr][0][1] = y - 64;
	if (ft_compare_locations(x, y - 64,
		map -> collectible, map -> collectible_nbr) != -1)
	{
		i = ft_compare_locations(x, y - 64,
			map -> collectible, map -> collectible_nbr);
		map -> collectible[i][0][0] = -42;
		map -> collectible[i][0][1] = -42;
		map -> collectible_status++;
	}
	if (x == map -> ex[0] && y - 64 == map -> ex[1])
		map -> ex_status = 0;
}

static	void	ft_movedown(t_map *map, int x, int y)
{
	int	i;

	map -> wall_nbr += 1;
	map -> wall[map -> wall_nbr][0][0] = x;
	map -> wall[map -> wall_nbr][0][1] = y + 64;
	if (ft_compare_locations(x, y + 64,
		map -> collectible, map -> collectible_nbr) != -1)
	{
		i = ft_compare_locations(x, y + 64,
			map -> collectible, map -> collectible_nbr);
		map -> collectible[i][0][0] = -42;
		map -> collectible[i][0][1] = -42;
		map -> collectible_status++;
	}
	if (x == map -> ex[0] && y + 64 == map -> ex[1])
		map -> ex_status = 0;
}

static	void	ft_move_around(t_map *map, int x, int y)
{
	if (ft_compare_locations(x + 64, y, map -> wall, map -> wall_nbr) == -1)
	{
		ft_moveright(map, x, y);
		ft_move_around(map, x + 64, y);
	}
	if (ft_compare_locations(x - 64, y, map -> wall, map -> wall_nbr) == -1)
	{
		ft_moveleft(map, x, y);
		ft_move_around(map, x - 64, y);
	}
	if (ft_compare_locations(x, y - 64, map -> wall, map -> wall_nbr) == -1)
	{
		ft_moveup(map, x, y);
		ft_move_around(map, x, y - 64);
	}
	if (ft_compare_locations(x, y + 64, map -> wall, map -> wall_nbr) == -1)
	{
		ft_movedown(map, x, y);
		ft_move_around(map, x, y + 64);
	}
	return ;
}

void	ft_check_path(t_map *map)
{
	t_map	clone;

	ft_memcpy(&clone, map, sizeof(t_map));
	ft_move_around(&clone, clone.player[0], clone.player[1]);
	if (clone.collectible_status < map ->collectible_nbr && clone.ex_status)
	{
		ft_printf("map does not have a valid path!\n");
		exit (1);
	}
}