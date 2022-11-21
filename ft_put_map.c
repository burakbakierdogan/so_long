/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:36:47 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/21 08:57:04 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"



static	void	ft_get_data(t_mlx *obj, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	obj -> mlx = mlx_init();
	obj -> mlx_window = mlx_new_window(obj -> mlx, (map -> res[0] * 64),
		(map -> res[1] * 64), "./so_long");
	obj -> wall = mlx_xpm_file_to_image(obj -> mlx, "./textures/wall.xpm", &x, &y);
	obj -> player = mlx_xpm_file_to_image(obj -> mlx, "./textures/player.xpm", &x, &y);
	obj -> space = mlx_xpm_file_to_image(obj -> mlx, "./textures/space.xpm", &x, &y);
	obj -> collectible = mlx_xpm_file_to_image(obj -> mlx, "./textures/collectible.xpm", &x, &y);
	obj -> ext = mlx_xpm_file_to_image(obj -> mlx, "./textures/ext.xpm", &x, &y);
}

void	ft_put_map(t_map *map, t_mlx *obj)
{
	ft_get_data(obj, map);

}