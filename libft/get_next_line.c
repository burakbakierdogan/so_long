/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/07/03 07:09:57 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_container(int fd, char *container)
{
	int		rret;
	char	*buf;

	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rret = 1;
	while (!ft_strchrr(container, '\n') && rret != 0)
	{
		rret = read (fd, buf, BUFFER_SIZE);
		if (rret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rret] = '\0';
		container = ft_str_merge(container, buf);
	}
	free (buf);
	return (container);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*container;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	container = ft_container(fd, container);
	if (!container)
		return (NULL);
	container = ft_container(fd, container);
	ret = ft_ret_line(container);
	container = ft_new_contaier(container);
	return (ret);
}
