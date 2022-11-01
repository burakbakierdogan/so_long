/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 05:46:40 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/29 05:46:40 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	void	*content;
	t_list	*new;
	t_list	*new_first;

	content = f (lst -> content);
	new_first = ft_lstnew(content);
	if (!new_first || !content)
	{
		del(content);
		return (NULL);
	}
	lst = lst -> next;
	while (lst)
	{
		content = f(lst -> content);
		new = ft_lstnew(content);
		if (!new || !content)
		{
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&new_first, new);
		lst = lst -> next;
	}
	return (new_first);
}
