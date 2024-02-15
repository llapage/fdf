/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 06:34:05 by llapage           #+#    #+#             */
/*   Updated: 2023/04/22 16:09:21 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!(s) || start > ft_strlen(s))
		new_str = malloc(1 * sizeof(char));
	else
	{
		if (len > ft_strlen(&s[start]))
			len = ft_strlen(&s[start]);
		new_str = malloc((len + 1) * sizeof(char));
	}
	if (!(new_str))
		return (NULL);
	i = 0;
	if (s && start <= ft_strlen(s))
	{
		while (len-- > 0)
			new_str[i++] = s[start++];
	}
	new_str[i] = '\0';
	return (new_str);
}
