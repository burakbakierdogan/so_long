/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:12:09 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/26 07:29:38 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/libft.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
	void	*wall;
	void	*collectible;
	void	*space;
	void	*ext;
	void	*player;
}	t_mlx;

typedef struct s_map
{
	int	res[2];
	int	wall[2048][1][2];
	int	wall_nbr;
	int	space[2048][1][2];
	int	space_nbr;
	int	player[2];
	int	collectible[2048][1][2];
	int	collectible_nbr;
	int	collectible_status;
	int	ex[2];
	int	ex_status;
	int	move;
	t_mlx	*obj;
}	t_map;

typedef struct s_nmap
{
	int	top;
	int	bottom;
	int	l_side;
	int	r_side;
	int	i;
	int	j;
}	t_nmap;

char	**ft_error_management(int fd,int ac, char *argv);
void	ft_check_walls(char **map);
void	ft_check_items(char **map);
void	ft_get_map_data(t_map *map, char **map_src);
void	ft_free_map_src(char **map_src);
void	ft_put_map(t_map *map, t_mlx *obj);
void	ft_key_events(t_map *map);
void	ft_check_path(t_map *map);
int		ft_compare_locations(int x, int y, int arr[2048][1][2], int size);
#endif