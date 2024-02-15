/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:23:43 by llapage           #+#    #+#             */
/*   Updated: 2023/06/27 14:11:28 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int	g_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size != 0)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		if (i < size)
			dest[i] = '\0';
	}
	return (src_len);
}

char	*g_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdupchr(const char *src, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	if (src[i] && src[i] == c)
		i++;
	new = malloc((i + 1) * sizeof(char));
	if (!(new))
		return (NULL);
	new[i] = '\0';
	i = 0;
	while (src[i] && src[i] != c)
	{
		new[i] = src[i];
		i++;
	}
	if (c && src[i] && src[i] == c)
		new[i] = src[i];
	return (new);
}

char	*g_strjoin(char const *s1, char const *s2)
{
	char	*strout;
	char	*strin;

	if (s1 && s2)
	{
		strin = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		if (strin)
		{
			strout = strin;
			while (*s1 != 0)
				*strin++ = *s1++;
			while (*s2 != 0)
				*strin++ = *s2++;
			*strin = '\0';
			return (strout);
		}
		return (NULL);
	}
	return (NULL);
}
