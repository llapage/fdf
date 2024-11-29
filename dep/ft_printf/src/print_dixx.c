/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dixx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:23:20 by llapage           #+#    #+#             */
/*   Updated: 2023/05/17 15:14:56 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	len_nb(long long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	print_d(long long n_arg)
{
	long long	nb;
	int			len;
	char		*str;

	len = 0;
	nb = n_arg;
	if (n_arg == 0)
		len = 1;
	else
		len = len_nb(nb);
	str = ft_itoa_l((long long)n_arg);
	if (!(str))
		return (-1);
	if (print_s(str) < 0)
		len = -1;
	free(str);
	return (len);
}

int	print_x(unsigned long long ptr, char f)
{
	int		ret;
	char	*str;

	ret = 0;
	ret += addr_len(ptr);
	str = ft_itoa_16(ptr, f);
	if (!str)
		return (-1);
	if (print_s(str) < 0)
		ret = -1;
	free(str);
	return (ret);
}
