/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:25:17 by llapage           #+#    #+#             */
/*   Updated: 2023/04/22 15:45:49 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_max(size_t result, int negative)
{
	if (negative == -1)
	{
		if (result <= LLONG_MAX)
			return (result);
		else
			return (0);
	}
	else
	{
		if (result > LLONG_MAX)
			return (-1);
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int			negative;
	int			i;
	size_t		result;

	negative = 1;
	i = 0;
	result = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || 57 < str[i])
			break ;
		else
			result = (result * 10) + (int)(str[i] - '0');
		i++;
	}
	return (check_max(result, negative) * negative);
}
