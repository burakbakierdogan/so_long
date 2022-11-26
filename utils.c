/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:58:26 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/26 13:19:33 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_nl(char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	return (i);
}

void	ft_free_map_src(char **map_src)
{
	int	i;

	i = 0;
	while (map_src[i])
		free(map_src[i++]);
	free(map_src);
}

void	ft_get_player_location(t_map *map, char **map_src, char c)
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
				map -> player[0] = x * 64;
				map -> player[1] = y * 64;
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_get_collectible_locations(t_map *map, char **map_src, char c)
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
				map -> collectible[map -> collectible_nbr][0][0] = 64 * x;
				map -> collectible[map -> collectible_nbr][0][1] = 64 * y;
				map -> collectible_nbr += 1;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_get_exit_location(t_map *map, char **map_src, char c)
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
				map -> ex[0] = x * 64;
				map -> ex[1] = y * 64;
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
