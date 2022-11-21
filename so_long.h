/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:12:09 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/21 06:13:37 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/libft.h"
typedef struct s_map
{
	int	res[2];
	int	wall[1024][1][2];
	int	wall_nbr;
	int	space[1024][1][2];
	int	space_nbr;
	int	player[2];
	int	collectible[1024][1][2];
	int	collectible_nbr;
	int	ex[2];
}	t_map;

typedef struct s_counters
{
	int	i;
	int	j;
	int	k;
	int	l;
}	t_counter;

char	**ft_error_management(int fd,int ac, char *argv);
void	ft_check_walls(char **map);
void	ft_check_items(char **map);
void	ft_get_map_data(t_map *map, char **map_src);
void	ft_free_map_src(char **map_src);
#endif