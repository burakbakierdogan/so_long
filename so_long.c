/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:10:31 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/15 00:56:01 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int main(int ac, char *argv[])
{
	char	**map;
	int		i;

	map = ft_error_management (open ("map.ber", O_RDONLY));
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}