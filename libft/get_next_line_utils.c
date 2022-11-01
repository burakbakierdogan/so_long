/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:01 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/25 17:27:12 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlenn(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchrr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_str_merge(char *container, char *buf)
{
	int		index;
	int		index2;
	char	*str;

	index = -1;
	index2 = 0;
	if (!container)
	{
		container = (char *) malloc (1 * sizeof(char));
		container[0] = '\0';
	}
	if (!container || !buf)
		return (NULL);
	str = malloc (ft_strlen(buf) + (ft_strlen(container) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (container)
		while (container[++index])
			str[index] = container[index];
	while (buf[index2])
		str[index++] = buf[index2++];
	str[ft_strlen(container) + ft_strlen(buf)] = '\0';
	free (container);
	return (str);
}

char	*ft_ret_line(char *container)
{
	int		index;
	char	*ret;

	index = 0;
	if (!container[index])
		return (NULL);
	while (container[index] && container[index] != '\n')
		index++;
	ret = (char *) malloc (sizeof(char) * (index + 2));
	if (!ret)
		return (NULL);
	index = 0;
	while (container[index] && container[index] != '\n')
	{
		ret[index] = container[index];
		index++;
	}
	if (container[index] == '\n')
	{
		ret[index] = container[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}

char	*ft_new_contaier(char *container)
{
	int		index;
	int		index2;
	char	*str;

	index = 0;
	while (container[index] && container[index] != '\n')
		index++;
	if (!container[index])
	{
		free (container);
		return (NULL);
	}
	str = (char *) malloc (sizeof(char) * (ft_strlen(container) - index + 1));
	if (!str)
		return (NULL);
	index++;
	index2 = 0;
	while (container[index])
		str[index2++] = container[index++];
	str[index2++] = '\0';
	free(container);
	return (str);
}
