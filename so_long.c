/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:10:31 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/26 07:20:54 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int main(int ac, char *argv[])
{
	t_map	map;
	t_mlx	obj;
	char	**map_src;

	map_src = ft_error_management (open (argv[1], O_RDONLY), ac, argv[1]);
	ft_get_map_data(&map, map_src);
	ft_check_path(&map);
	ft_put_map(&map, &obj);
	map.obj = &obj;
	ft_key_events(&map, &obj);
	mlx_loop(obj.mlx);
}