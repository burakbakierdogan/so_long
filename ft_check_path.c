/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:36:19 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/26 12:49:10 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_path(t_map *map)
{
	t_map	clone;

	ft_memcpy(&clone, map, sizeof(t_map));
	ft_move_around(&clone, clone.player[0], clone.player[1]);
	if (clone.collectible_status < map ->collectible_nbr || clone.ex_status)
	{
		ft_printf("Map does not have a valid path!\n");
		exit (1);
	}
}
