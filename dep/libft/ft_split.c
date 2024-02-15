/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 08:16:23 by llapage           #+#    #+#             */
/*   Updated: 2023/06/30 17:40:06 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!(str))
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i + 1] != '\0')
			i++;
		if (str[i] != c)
			count++;
		while (str[i] != c && str[i + 1] != '\0')
			i++;
		i++;
	}
	return (count);
}

static char	*new_word(char const *s, char c)
{
	int		i;
	char	*new;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!(new))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void	ft_free(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

static int	create_words(char **list, char const *s, char c, int count)
{
	int	i;

	i = 0;
	if (count != 0)
	{
		while (*s && i < count)
		{
			while (*s && *s == c)
				s++;
			if (*s)
				list[i++] = new_word(s, c);
			if (list[i - 1] == NULL)
			{
				ft_free(list);
				return (0);
			}
			while (*s && *s != c)
				s++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**list;

	count = count_words(s, c);
	list = malloc(sizeof(char *) * (count + 1));
	if (!(list))
		return (NULL);
	list[count] = 0;
	if (!(create_words(list, s, c, count)))
		return (NULL);
	return (list);
}
