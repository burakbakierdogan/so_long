/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 06:15:48 by berdogan          #+#    #+#             */
/*   Updated: 2022/03/26 14:59:58 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		n;
	char	a;

	a = (unsigned char) c;
	n = ft_strlen (s) + 1;
	while (n--)
	{
		if (*s == a)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
