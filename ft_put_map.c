/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:36:47 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/26 13:17:38 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static	void	ft_put_walls_spaces(t_mlx *obj, t_map *map)
{
	int	i;

	i = 0;
	while (i < map -> wall_nbr)
	{
		mlx_put_image_to_window(obj -> mlx, obj -> mlx_window,
			obj -> wall, map ->wall[i][0][0], map -> wall[i][0][1]);
		i++;
	}
	i = 0;
	while (i < map -> space_nbr)
	{
		mlx_put_image_to_window(obj -> mlx, obj -> mlx_window,
			obj -> space, map -> space[i][0][0], map -> space[i][0][1]);
		i++;
	}
	i = 0;
	while (i < map -> collectible_nbr)
	{
		mlx_put_image_to_window(obj -> mlx, obj -> mlx_window,
			obj -> collectible, map -> collectible[i][0][0],
			map -> collectible[i][0][1]);
		i++;
	}
}

static	void	ft_create_map(t_mlx *obj, t_map *map)
{
	ft_put_walls_spaces(obj, map);
	mlx_put_image_to_window(obj -> mlx, obj -> mlx_window,
		obj -> player, map -> player[0], map -> player[1]);
	mlx_put_image_to_window(obj -> mlx, obj -> mlx_window,
		obj -> space, map -> ex[0], map -> ex[1]);
}

static	void	ft_get_data(t_mlx *obj, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	obj -> mlx = mlx_init();
	obj -> mlx_window = mlx_new_window(obj -> mlx, (map -> res[0] * 64),
			(map -> res[1] * 64), "./so_long");
	obj -> wall = mlx_xpm_file_to_image(obj -> mlx,
			"./textures/wall.xpm", &x, &y);
	obj -> player = mlx_xpm_file_to_image(obj -> mlx,
			"./textures/player.xpm", &x, &y);
	obj -> space = mlx_xpm_file_to_image(obj -> mlx,
			"./textures/ground.xpm", &x, &y);
	obj -> collectible = mlx_xpm_file_to_image(obj -> mlx,
			"./textures/collectible.xpm", &x, &y);
	obj -> ext = mlx_xpm_file_to_image(obj -> mlx,
			"./textures/exit.xpm", &x, &y);
}

void	ft_put_map(t_map *map, t_mlx *obj)
{
	ft_get_data(obj, map);
	ft_create_map(obj, map);
}
