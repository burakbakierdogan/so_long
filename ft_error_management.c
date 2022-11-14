/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:13:47 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/14 23:10:12 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_check_side_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map [0][j] != '\n')
		j++;
	j--;
	while (map[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
		{
			ft_printf("side wall :error\n");
			exit(1);
		}
		i--;
	}
}

static	void	ft_check_bottom_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	i--;
	ft_printf("%s\n", map[i][j]);
	if (i < 2)
	{
		ft_printf("edsef error\n");
		exit (1);
	}
	while (map[i][j])
	{
		if (map[i][j] != '1')
		{
			ft_printf("b: error\n");
			exit(1);
		}
		j++;
	}
}

static	void	ft_check_top_wall(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j])
		j++;
	j--;
	while (map[0][i] != '\n' && map[0][i])
	{
		if (map[0][i] != '1')
		{
			ft_printf ("top :error\n");
			exit (1);
		}
		i++;
	}
	i--;
	if (i < 2 || i-1 == j)
	{
		ft_printf (" a error\n");
		exit (1);
	}
}

static	void	ft_check(char **map)
{
	ft_check_top_wall(map);
	ft_check_bottom_wall(map);
	ft_check_side_walls(map);
}
char	**ft_error_management(int fd)
{
	char	**map;
	char	*str;
	int		i;

	i = 0;
	ft_printf("%d\n", fd);
	map = (char **) malloc (sizeof(char *) * 1000);
	if (!map)
		return (NULL);
	str = get_next_line (fd);
	ft_printf("%d\n", str);
	map[i++] = str;

	while (str)
	{
		str = get_next_line(fd);
		map[i++] = str;
	}
	//close (fd);
}

/*
map and its content need to be freed.
*/