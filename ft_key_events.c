/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:20:43 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/22 13:47:15 by berdogan         ###   ########.fr       */
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
	int	i;

	if (ft_compare_locations(vars -> player[0] + 64,
		vars -> player[1], vars -> wall, vars -> wall_nbr) != -1)
		return ;
	vars -> player[0] += 64;
	mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
		vars -> obj -> player, vars -> player[0], vars -> player[1]);
	mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
		vars -> obj -> space, vars -> player[0] - 64, vars -> player[1]);
	if (ft_compare_locations(vars -> player[0], vars -> player[1],
		vars -> collectible, vars -> collectible_nbr) != -1)
	{
		i = ft_compare_locations(vars -> player[0], vars -> player[1],
			vars -> collectible, vars -> collectible_nbr);
		vars -> collectible[i][0][0] = 0;
		vars -> collectible[i][0][1] = 1;
		vars -> collectible_status++;
	}
	if ((vars -> player[0] == vars -> ex[0] && vars -> player[1] == vars -> ex[1]) &&
		vars -> collectible_status == vars -> collectible_nbr)
			exit(1);
}
static	void	ft_move_left(t_map *vars)
{
	int	i;

	if (ft_compare_locations(vars -> player[0] - 64,
		vars -> player[1], vars -> wall, vars -> wall_nbr) != -1)
		return ;
	vars -> player[0] -= 64;
	mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
		vars -> obj -> player, vars -> player[0], vars -> player[1]);
	mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
		vars -> obj -> space, vars -> player[0] + 64, vars -> player[1]);
	if (ft_compare_locations(vars -> player[0], vars -> player[1],
		vars -> collectible, vars -> collectible_nbr) != -1)
	{
		i = ft_compare_locations(vars -> player[0], vars -> player[1],
			vars -> collectible, vars -> collectible_nbr);
		vars -> collectible[i][0][0] = 0;
		vars -> collectible[i][0][1] = 0;
		vars -> collectible_status++;
	}

	if ((vars -> player[0] == vars -> ex[0] && vars -> player[1] == vars -> ex[1]) &&
		vars -> collectible_status == vars -> collectible_nbr)
			exit(1);
}

static	void	ft_move_down(t_map *vars)
{
	int	i;
	if (ft_compare_locations(vars -> player[0],
		vars -> player[1] + 64, vars -> wall, vars -> wall_nbr) != -1)
			return ;
	vars -> player[1] += 64;
	mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
		vars -> obj -> player, vars -> player[0], vars -> player[1]);
	mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
		vars -> obj -> space, vars -> player[0], vars -> player[1] - 64);
	if (ft_compare_locations(vars -> player[0], vars -> player[1],
		vars -> collectible, vars -> collectible_nbr) != -1)
	{
		i = ft_compare_locations(vars -> player[0], vars -> player[1],
			vars -> collectible, vars -> collectible_nbr);
		vars -> collectible[i][0][0] = 0;
		vars -> collectible[i][0][1] = 0;
		vars -> collectible_status++;
	}
	if ((vars -> player[0] == vars -> ex[0] && vars -> player[1] == vars -> ex[1]) &&
		vars -> collectible_status == vars -> collectible_nbr)
			exit(1);
	ft_printf("\a");

}

static	void	ft_move_up(t_map *vars)
{
	int	i;

	if (ft_compare_locations(vars -> player[0],
		vars -> player[1] - 64, vars -> wall, vars -> wall_nbr) != -1)
			return ;
	vars -> player[1] -= 64;
	mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
		vars -> obj -> player, vars -> player[0], vars -> player[1]);
	mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
		vars -> obj -> space, vars -> player[0], vars -> player[1] + 64);
	if (ft_compare_locations(vars -> player[0], vars -> player[1],
		vars -> collectible, vars -> collectible_nbr) != -1)
	{
		i = ft_compare_locations(vars -> player[0], vars -> player[1],
			vars -> collectible, vars -> collectible_nbr);
		vars -> collectible[i][0][0] = 0;
		vars -> collectible[i][0][1] = 0;
		vars -> collectible_status++;
	}
	ft_printf("\a");
	if ((vars -> player[0] == vars -> ex[0] && vars -> player[1] == vars -> ex[1]) &&
		vars -> collectible_status == vars -> collectible_nbr)
			exit(1);
}

static	int	ft_action(int keycode, t_map *vars)
{

	if (keycode == 2)
		ft_move_right(vars);
	if (keycode == 0)
		ft_move_left(vars);
	if (keycode == 1)
		ft_move_down(vars);
	if (keycode == 13)
		ft_move_up(vars);
	if (vars -> collectible_status == vars -> collectible_nbr)
		mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
			vars -> obj -> ext, vars -> ex[0], vars -> ex[1]);
	return (0);
}

void	ft_key_events(t_map *map, t_mlx *obj)
{
	t_vars vars;

	vars.map = map;
	vars.obj = obj;
	mlx_hook(obj -> mlx_window, 2, 1L<<0, ft_action, map);
}