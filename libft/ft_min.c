/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:39:53 by berdogan          #+#    #+#             */
/*   Updated: 2022/11/24 11:41:28 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int *tab, int len)
{
	int	index;
	int	len2;
	int	total;

	total = len;
	len--;
	index = 0;
	len2 = len;
	while (len >= 0)
	{
		while (len2 >= 0)
		{
			if (tab[len] <= tab[len2])
				index++;
			if (index == total)
				return (tab[len]);
			len2--;
		}
		len2 = total - 1;
		len--;
		index = 0;
	}
	return (0);
}