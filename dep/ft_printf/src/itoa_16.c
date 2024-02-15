/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_16.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:00:26 by llapage           #+#    #+#             */
/*   Updated: 2023/06/25 18:13:42 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	itoa_length(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_put_in_str(char *str, long long nb, char f, int len)
{
	while (nb != 0 && len >= 0)
	{
		if (nb % 16 <= 9)
			str[len-- - 1] = nb % 16 + '0';
		else if (f == 'x')
			str[len-- - 1] = nb % 16 - 10 + 'a';
		else
			str[len-- - 1] = nb % 16 - 10 + 'A';
		nb = nb / 16;
	}
}

char	*ft_itoa_16(long long n, char f)
{
	char		*str;
	int			len;
	long long	nb;

	nb = (long long) n;
	len = itoa_length(nb);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	ft_put_in_str(&str[0], nb, f, len);
	return (str);
}
