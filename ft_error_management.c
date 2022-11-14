/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:13:47 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/15 01:03:44 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_error_management(int fd)
{
	char	**map;
	char	*str;
	int		i;

	i = 0;
	map = (char **) malloc (sizeof(char *) * 1000);
	if (!map)
		return (NULL);
	str = get_next_line (fd);
	map[i++] = str;
	while (str)
	{
		str = get_next_line(fd);
		map[i++] = str;
	}
	i = 0;
	ft_check_walls(map);
	ft_printf("OK\n");
	close (fd);
	return(map);

}

/*
map and its content need to be freed.
*/