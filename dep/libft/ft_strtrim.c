/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:07:51 by llapage           #+#    #+#             */
/*   Updated: 2023/04/17 13:56:52 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (set)
	{
		while (len > 0 && s[len - 1] && ft_strchr(set, s[len - 1]))
			len--;
		i = -1;
		while (len > 0 && s[len - 1] && ft_strchr(set, s[++i]))
			len--;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	s += i;
	i = -1;
	while (++i < len)
		str[i] = *s++;
	return (str);
}
