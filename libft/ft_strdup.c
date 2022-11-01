/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:33:33 by berdogan          #+#    #+#             */
/*   Updated: 2022/03/29 17:09:09 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *) malloc (sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(str))
	{
		*((char *) ptr + i) = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
