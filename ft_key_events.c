/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:20:43 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/22 05:47:59 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static	int	ft_compare_locations(int x, int y, int arr[1024][1][2], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (x == arr[i][0][0] && y == arr[i][0][1])
			return (i);
		i++;
	}
	return (-1);
}

static	void	ft_move_right(t_map *vars)
{

	if (ft_compare_locations(vars -> player[0] + 64,
		vars -> player[1], vars -> wall, vars -> wall_nbr) != -1)
		return ;
	vars -> player[0] += 64;
	mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
		vars -> obj -> player, vars -> player[0], vars -> player[1]);
	if ((vars -> player[0] == vars -> ex[0] && vars -> player[1] == vars -> ex[1]))
		mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
			vars -> obj -> door_p, vars -> player[0], vars -> player[1]);
	else
		mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
			vars -> obj -> space, vars -> player[0] - 64, vars -> player[1]);
	if (ft_compare_locations(vars -> player[0],
		vars -> player[1], vars -> collectible, vars -> collectible_nbr) != -1)
	{
		vars -> collectible_status++;
		vars -> collectible[ft_compare_locations(vars -> player[0],
			vars -> player[1], vars -> collectible, vars -> collectible_nbr)][0][0] = 0;
		vars -> collectible[ft_compare_locations(vars -> player[0],
			vars -> player[1], vars -> collectible, vars -> collectible_nbr)][0][1] = 0;
	}
	if ((vars -> player[0] == vars -> ex[0] && vars -> player[1] == vars -> ex[1]) &&
		vars -> collectible_nbr == 0)
	{
		exit(1);
	}
}
static	void	ft_move_left(t_map *vars)
{
	if (ft_compare_locations(vars -> player[0] - 64,
		vars -> player[1], vars -> wall, vars -> wall_nbr) != -1)
		return ;
	vars -> player[0] -= 64;
	mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
		vars -> obj -> player, vars -> player[0], vars -> player[1]);
	if ((vars -> player[0] == vars -> ex[0] && vars -> player[1] == vars -> ex[1]))
		mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
			vars -> obj -> door_p, vars -> player[0], vars -> player[1]);
	else
		mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
			vars -> obj -> space, vars -> player[0] + 64, vars -> player[1]);
	if (ft_compare_locations(vars -> player[0],
		vars -> player[1], vars -> collectible, vars -> collectible_nbr) != -1)
	{
		vars -> collectible_status++;
		vars -> collectible[ft_compare_locations(vars -> player[0],
			vars -> player[1], vars -> collectible, vars -> collectible_nbr)][0][0] = 0;
		vars -> collectible[ft_compare_locations(vars -> player[0],
			vars -> player[1], vars -> collectible, vars -> collectible_nbr)][0][1] = 0;
	}
	if ((vars -> player[0] == vars -> ex[0] && vars -> player[1] == vars -> ex[1]) &&
		vars -> collectible_status == vars -> collectible_nbr)
			exit(1);
}

static	int	ft_action(int keycode, t_map *vars)
{

	if (keycode == 100)
		ft_move_right(vars);
	if (keycode == 97)
		ft_move_left(vars);
	return (0);
}

void	ft_key_events(t_map *map, t_mlx *obj)
{
	t_vars vars;

	vars.map = map;
	vars.obj = obj;
	mlx_hook(obj -> mlx_window, 2, 1L<<0, ft_action, map);
}