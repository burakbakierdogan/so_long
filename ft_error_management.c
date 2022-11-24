/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:13:47 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/24 18:42:37 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_check_fd_ac_ber(int fd, int ac, char *str)
{
	int	len;

	if (ac != 2)
	{
		ft_printf("AC Error\n");
		exit (1) ;
	}
	len = ft_strlen(str) - 1;
	if (fd < 0)
	{
		perror ("fd error");
		exit (1);
	}
	if (str[len] == 'r' && str[len - 1] == 'e' &&
		str[len - 2] == 'b' && str[len - 3] == '.')
			return ;
	else
	{
		ft_printf("Map is not a ber file!\n");
		exit (1);
	}
}

static	char	**ft_create_new_map(char **map)
{
	int		i;
	char	**new;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	new = malloc (sizeof(char *) * (i + 1));
	if (!new)
	{
		perror("malloc failed");
		exit(1);
	}
	i = -1;
	while (map[++i])
		new[i] = ft_strdup(map[i]);
	return (new);
}

static	void	ft_alter_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[++i])
	{
		while (map[i][++j])
			if (map[i][j] == 'C' || map[i][j] == 'P'
			|| map[i][j] == 'E')
				map[i][j] = '2';
		j = 0;
	}
}

int	ft_get_top(char **src)
{
	int	i;
	int	j;
	int	top;

	i = -1;
	j = 0;
	top = 0;
	while (src[++i])
	{
		while (src[i][++j])
			if (src[i][j] == '2')
					return (top);
		j = 0;
		top++;
	}
	return (top);
}

int	ft_get_bottom(char **src)
{
	int	i;
	int	j;
	int	bottom;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i])
		i++;
	bottom = i - 1;
	while (--i >= 0)
	{
		while (src[i][++j])
			if (src[i][j] == '2')
					return (bottom);
		j = 0;
		bottom--;
	}
	return (bottom);
}

void	ft_get_sides(char **src, t_nmap *nmap)
{
	int	i;
	int	j;
	int	*ptr;
	int	k;

	i = -1;
	j = -1;
	k = 0;
	ptr = malloc (sizeof(int) * 1024);
	if (!ptr)
	{
		perror("malloc error!\n");
		exit(1);
	}
	while (src[++i])
	{
		while (src[i][++j])
			if (src[i][j] == '2')
				ptr[k++] = j;
		j = -1;
	}
	nmap -> l_side = ft_min(ptr, k);
	nmap -> r_side = ft_max(ptr, k);
	free(ptr);
}

int	ft_check_vertical_line(char **map, t_nmap *nmap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nmap -> top <= nmap -> bottom)
	{

	}
}

void	ft_walk_path(char **map, t_nmap *nmap)
{
	int	i;
	int	k;

	k = 0;
	i = nmap -> l_side;
	while (nmap -> top <= nmap -> bottom)
	{
		while (nmap -> l_side++ <= nmap -> r_side)
		{
			if (map[nmap -> top][nmap -> l_side] == '0'
				|| map[nmap -> top][nmap -> l_side] == '2')
				k++;
		}
		if (k == 0)
		{
			ft_printf("map path error\n");
			exit (1);
		}
		k = 0;
		nmap -> l_side = i;
		nmap -> top++;
	}
}

static	void	ft_check_path(char **map)
{
	char		**new_map;
	t_nmap	nmap;

	new_map = ft_create_new_map(map);
	ft_alter_map(new_map);
	nmap.top= ft_get_top(new_map);
	nmap.bottom = ft_get_bottom(new_map);
	ft_get_sides(new_map, &nmap);
	ft_walk_path(new_map, &nmap);
	ft_printf("top = %d  bottom = %d  left = %d  right =%d\n"
		, nmap.top, nmap.bottom, nmap.l_side, nmap.r_side);
	ft_free_map_src(new_map);
}

char	**ft_error_management(int fd,int ac, char *argv)
{
	char	**map;
	char	*str;
	int		i;

	i = 0;
	ft_check_fd_ac_ber(fd, ac, argv);
	map = (char **) malloc (sizeof(char *) * 1000);
	if (!map)
	{
		perror("malloc failure");
		exit (1);
	}
	str = get_next_line (fd);
	map[i++] = str;
	while (str)
	{
		str = get_next_line(fd);
		map[i++] = str;
	}
	ft_check_walls(map);
	ft_check_items(map);
	ft_check_path(map);
	close (fd);
	return (map);
}