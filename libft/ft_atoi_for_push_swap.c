/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_for_push_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:56:00 by berdogan          #+#    #+#             */
/*   Updated: 2022/10/16 01:55:25 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_for_push_swap(const char *nptr)
{
	int				i;
	int				sign;
	unsigned int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!ft_strncmp(nptr, "-2147483648", 11))
		return (-2147483648);
	while (ft_is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		res = (res * 10) + (nptr[i++] - '0');
	if (res > INT_MAX && sign == -1)
		return (0);
	if (res > INT_MAX && sign == 1)
		return (-1);
	return (res * sign);
}
