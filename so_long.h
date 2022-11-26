/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:12:09 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/26 13:02:00 by berdogan         ###   ########.fr       */
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

char	**ft_error_management(int fd,int ac, char *argv);
void	ft_check_walls(char **map);
void	ft_check_items(char **map);
void	ft_get_map_data(t_map *map, char **map_src);
void	ft_free_map_src(char **map_src);
void	ft_put_map(t_map *map, t_mlx *obj);
void	ft_key_events(t_map *map);
void	ft_check_path(t_map *map);
int		ft_compare_locations(int x, int y, int arr[2048][1][2], int size);
void	ft_moveright(t_map *map, int x, int y);
void	ft_moveleft(t_map *map, int x, int y);
void	ft_movedown(t_map *map, int x, int y);
void	ft_move_around(t_map *map, int x, int y);
int		ft_strlen_nl(char *src);
void	ft_get_player_location(t_map *map, char **map_src, char c);
void	ft_get_collectible_locations(t_map *map, char **map_src, char c);
void	ft_get_exit_location(t_map *map, char **map_src, char c);
void	ft_move_up(t_map *vars);
void	ft_move_down(t_map *vars);
void	ft_move_left(t_map *vars);
void	ft_exit(t_map *map, int status);
void	ft_move_right(t_map *vars);
#endif