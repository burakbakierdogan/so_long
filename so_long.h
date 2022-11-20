/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:12:09 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/20 22:46:00 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_map
{
	int	res[2];
	int	**wall;
	int	wall_nbr;
	int	**space;
	int	space_nbr;
	int	player[2];
	int	**collectible;
	int	ex[2];
}	t_map;

#include "libft/libft.h"

void	ft_error_management(int fd,int ac, char *argv);
void	ft_check_walls(char **map);
void	ft_check_items(char **map);
#endif