/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_any.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:58:36 by llapage           #+#    #+#             */
/*   Updated: 2023/05/23 11:03:11 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_c(char c)
{
	int	ret;

	ret = write(1, &c, 1);
	return (ret);
}

int	print_s(char *s)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (write(1, &s[i++], 1) < 0)
				return (-1);
			else
				ret++;
		}
	}
	else
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		ret = 6;
	}
	return (ret);
}

int	addr_len(unsigned long long ptr)
{
	int	i;

	i = 1;
	while (ptr >= 16)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

int	put_addr(unsigned long long ptr, char f)
{
	char	c;
	char	c2;
	int		ret;

	ret = 1;
	c = ptr + '0';
	c2 = ptr - 10 + 'a';
	if (ptr >= 16)
	{
		put_addr(ptr / 16, f);
		put_addr(ptr % 16, f);
	}
	else
	{
		if (ptr <= 9)
			ret = write(1, &c, 1);
		else
		{
			if (f == 'X')
				c2 = c2 - 32;
			ret = write(1, &c2, 1);
		}
	}
	return (ret);
}

int	print_p(unsigned long long ptr, char f)
{
	int	ret;

	if (print_s("0x") < 0)
		return (-1);
	if (ptr == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (3);
	}
	ret = 2;
	ret += addr_len(ptr);
	if (put_addr(ptr, f) == -1)
		return (-1);
	return (ret);
}
