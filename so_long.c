/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:10:31 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/15 01:40:06 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int main(int ac, char *argv[])
{
	char	**map;
	int		i;

	if (ac != 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	map = ft_error_management (open (argv[1], O_RDONLY));
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}