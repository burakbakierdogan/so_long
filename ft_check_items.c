/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 01:19:42 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/15 01:35:14 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static	void	ft_check(char **map, char c)
{
	int	i;
	int	j;
	int	total;

	i = 0;
	total = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
				total++;
			j++;
		}
		j = 0;
		i++;
	}
	if ((total == 0 || total > 1) && (c == 'P' || c == 'E'))
	{
		ft_printf ("Error\n");
		exit (1);
	}
	if ((c == 'C' || c == '0') && total == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	ft_check_items(char **map)
{
	ft_check(map, 'E');
	ft_check(map, 'P');
	ft_check(map, 'C');
	ft_check(map, '0');
}