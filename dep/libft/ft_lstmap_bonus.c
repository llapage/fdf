/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:31:27 by llapage           #+#    #+#             */
/*   Updated: 2023/04/30 14:28:23 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*new_node;

	new = NULL;
	if (lst && del && f)
	{
		while (lst)
		{
			new_node = f(lst->content);
			tmp = ft_lstnew(new_node);
			if (!tmp)
			{
				ft_lstclear(&new, del);
				del(new_node);
				return (NULL);
			}
			ft_lstadd_back(&new, tmp);
			lst = lst->next;
		}
	}
	return (new);
}
