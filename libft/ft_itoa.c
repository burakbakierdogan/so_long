/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:09:40 by berdogan          #+#    #+#             */
/*   Updated: 2022/03/26 14:58:54 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sizer(int n)
{
	int	i;
	int	number;

	i = 0;
	if (n == -2147483648)
		return (12);
	if (n == 0)
		return (2);
	number = n;
	if (number < 0)
		number *= -1;
	while (number > 0)
	{
		number /= 10;
		i++;
	}
	if (n < 0)
		return (i + 2);
	return (i + 1);
}

static	char	*ft_putnbr(char *str, int n)
{
	int	index;
	int	number;

	number = n;
	index = ft_sizer(n) - 1;
	if (n < 0)
	{
		n *= -1;
	}
	while (index-- > 0)
	{
		str[index] = (n % 10) + 48;
		n /= 10;
	}
	if (number < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_sizer(n);
	str = (char *) ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", size);
		return (str);
	}
	if (n == 0)
	{
		ft_strlcpy(str, "0", size);
		return (str);
	}
	str = ft_putnbr(str, n);
	return (str);
}
