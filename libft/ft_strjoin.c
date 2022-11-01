/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 05:18:03 by berdogan          #+#    #+#             */
/*   Updated: 2022/03/26 15:00:19 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	total;
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	total = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str = (char *) ft_calloc(total, sizeof(char));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (i < total && k < ft_strlen(s2))
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	return (str);
}
