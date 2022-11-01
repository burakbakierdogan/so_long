/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:04:21 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/25 14:04:21 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

int	ft_lenn(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_append(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*new;

	i = ft_lenn (str1);
	j = ft_lenn (str2);
	new = malloc(sizeof(char) * (i + j + 1));
	i = 0;
	j = 0;
	if (str1)
	{
		while (str1[i])
		{
			new[i] = str1[i];
			i++;
		}
	}
	while (str2[j])
		new[i++] = str2[j++];
	new[i] = '\0';
	free (str1);
	return (new);
}

char	*ft_move_rest(char *rest, char *to_free)
{
	int		i;
	char	*new;

	i = 0;
	if (rest[i])
	{
		while (rest[i])
			i++;
		new = malloc((i + 1) * sizeof(char));
		i = -1;
		while (rest[++i])
			new[i] = rest[i];
		new[i] = '\0';
		free (to_free);
		return (new);
	}
	else
	{
		free (to_free);
		return (NULL);
	}
}

t_gnl	ft_seperate(char *str, int j)
{
	char	*new;
	int		i;
	t_gnl	ret_val;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	new = (char *) malloc ((i + 2) * sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	ret_val.str = new;
	ret_val.rest = ft_move_rest(str + i, str);
	ret_val.status = j;
	return (ret_val);
}
