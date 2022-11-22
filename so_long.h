/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:12:09 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/22 05:45:46 by berdogan         ###   ########.fr       */
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
	void	*door_p;
}	t_mlx;

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
	int	collectible_status;
	int	ex[2];
	t_mlx	*obj;
}	t_map;



typedef struct s_vars
{
	t_mlx *obj;
	t_map *map;
}	t_vars;

char	**ft_error_management(int fd,int ac, char *argv);
void	ft_check_walls(char **map);
void	ft_check_items(char **map);
void	ft_get_map_data(t_map *map, char **map_src);
void	ft_free_map_src(char **map_src);
void	ft_put_map(t_map *map, t_mlx *obj);
void	ft_key_events(t_map *map, t_mlx *obj);
#endif