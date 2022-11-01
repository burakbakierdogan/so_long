/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:40:25 by berdogan          #+#    #+#             */
/*   Updated: 2022/03/26 17:02:19 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest == src || !n)
		return (dest);
	if (src < dest)
	{
		while (n--)
		{
			*((unsigned char *) dest + n) = *((unsigned char *) src + n);
		}
		return (dest);
	}
	else
	{
		while (n--)
		{
			*((unsigned char *) dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}
