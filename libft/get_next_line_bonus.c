/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:04:00 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/25 18:09:43 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_gnl	ft_read(char *rest, int fd)
{
	t_gnl	ret_val;
	char	*new;
	int		i;

	i = 2;
	new = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (i > 0)
	{
		i = read(fd, new, BUFFER_SIZE);
		new[i] = '\0';
		if (ft_is_nl(new))
		{
			rest = ft_append(rest, new);
			break ;
		}
		else
		rest = ft_append(rest, new);
	}
	free(new);
	ret_val = ft_seperate (rest, i);
	return (ret_val);
}

char	*get_next_line_bonus(int fd)
{
	static char	*container[99999];
	t_gnl		ret_vals;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (container[fd] && ft_is_nl (container[fd]))
	{
		ret_vals = ft_seperate (container[fd], 1);
		container[fd] = ret_vals.rest;
		return (ret_vals.str);
	}
	else
	{
		ret_vals = ft_read (container[fd], fd);
		container[fd] = ret_vals.rest;
	}
	if (!ret_vals.rest && ret_vals.status <= 0)
	{
		free (ret_vals.str);
		return (NULL);
	}
	if (ret_vals.str)
		return (ret_vals.str);
	else
		return (NULL);
}
