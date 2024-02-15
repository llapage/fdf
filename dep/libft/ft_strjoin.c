/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 06:55:04 by llapage           #+#    #+#             */
/*   Updated: 2023/06/25 18:15:16 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
