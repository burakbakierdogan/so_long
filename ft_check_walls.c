/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 01:01:07 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/26 11:57:17 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_check_side_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map [0][j] != '\n')
		j++;
	j--;
	while (map[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
		{
			ft_printf("Error\n");
			exit(1);
		}
		i--;
	}
}

static	void	ft_check_bottom_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	i--;
	if (i < 2)
	{
		ft_printf("Error\n");
		exit (1);
	}
	while (map[i][j])
	{
		if (map[i][j] != '1')
		{
			ft_printf("Error\n");
			exit(1);
		}
		j++;
	}
}

static	void	ft_check_top_wall(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j])
		j++;
	j--;
	while (map[0][i] != '\n' && map[0][i])
	{
		if (map[0][i] != '1')
		{
			ft_printf ("Error\n");
			exit (1);
		}
		i++;
	}
	i--;
	if (i < 2 || i == j)
	{
		ft_printf ("Error\n");
		exit (1);
	}
}

void	ft_check_walls(char **map)
{
	ft_check_top_wall(map);
	ft_check_bottom_wall(map);
	ft_check_side_walls(map);
}
