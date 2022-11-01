/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:26:43 by berdogan          #+#    #+#             */
/*   Updated: 2022/10/03 02:54:24 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*begin;

	if (!lst)
		return (NULL);
	begin = lst;
	while (begin -> next != NULL)
	{
		if (!begin -> next)
			return (begin);
		begin = begin -> next;
	}
	return (begin);
}
