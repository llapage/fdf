/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:45:08 by llapage           #+#    #+#             */
/*   Updated: 2023/04/06 11:43:15 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cpy;
	char	*original;

	if (dest == NULL && src == NULL)
		return (NULL);
	cpy = (char *)dest;
	original = (char *)src;
	while (n-- > 0)
		*cpy++ = *original++;
	return (dest);
}
