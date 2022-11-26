/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:20:43 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/26 14:27:19 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_exit(t_map *map, int status)
{
	free(map -> obj -> ext);
	free(map -> obj -> player);
	free(map -> obj -> space);
	free(map -> obj -> collectible);
	free(map -> obj -> wall);
	free(map -> obj -> mlx);
	free(map -> obj -> mlx_window);
	if (status)
		ft_printf("Congratulations! You Win!\n");
	exit (1);
}

int	ft_compare_locations(int x, int y, int arr[2048][1][2], int size)
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

static	int	ft_action(int keycode, t_map *vars)
{
	if (keycode == D)
		ft_move_right(vars);
	if (keycode == A)
		ft_move_left(vars);
	if (keycode == S)
		ft_move_down(vars);
	if (keycode == W)
		ft_move_up(vars);
	if (keycode == ESC)
		ft_exit(vars, 0);
	else
		ft_print(vars);
	if (vars -> collectible_status == vars -> collectible_nbr)
		mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
			vars -> obj -> ext, vars -> ex[0], vars -> ex[1]);
	return (0);
}

static	int	ft_close(int keycode, t_map *map)
{
	keycode = 0;
	ft_exit(map, keycode);
	return (0);
}

void	ft_key_events(t_map *map)
{
	mlx_hook(map -> obj -> mlx_window, 17, 0, ft_close, map);
	mlx_hook(map -> obj -> mlx_window, 2, 1L << 0, ft_action, map);
}
