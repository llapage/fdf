/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:54:59 by llapage           #+#    #+#             */
/*   Updated: 2023/04/22 16:00:30 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)haystack;
	i = 0;
	j = 0;
	if (((!haystack) || (!needle)) && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return (str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == needle[j] && str[i + j] != 0 && j + i < len)
		{
			j++;
			if (j == ft_strlen(needle))
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
