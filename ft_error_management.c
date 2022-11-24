/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:13:47 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/24 11:43:10 by berdogan         ###   ########.fr       */
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

static	void	ft_get_distance(char **map)
{
	int	i;
	int	j;
	int	k;
	int	arr[1024];

	i = 0;
	j = 0;
	k = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '2')
				arr[k++] = j;
		}
	}
	k = ft_

}

static	void	ft_check_path(char **map)
{
	char	**new_map;

	new_map = ft_create_new_map(map);
	ft_alter_map(new_map);


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