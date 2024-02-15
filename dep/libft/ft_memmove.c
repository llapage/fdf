/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:19:20 by llapage           #+#    #+#             */
/*   Updated: 2023/04/06 11:45:53 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*strsrc;
	char	*strdst;

	if (dst == NULL && src == NULL)
		return (NULL);
	strsrc = (char *)src;
	strdst = (char *)dst;
	if (strsrc < strdst)
	{
		strsrc = strsrc + len - 1;
		strdst = strdst + len - 1;
		while (len-- > 0)
			*strdst-- = *strsrc--;
	}
	else
	{
		while (len-- > 0)
			*strdst++ = *strsrc++;
	}
	return (dst);
}
