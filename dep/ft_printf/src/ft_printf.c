/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:01:24 by llapage           #+#    #+#             */
/*   Updated: 2023/05/23 16:16:18 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			printed;
	int			i;
	int			ret;

	printed = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret = print_format(format[i + 1], args);
			i++;
		}
		else
			ret = print_c(format[i]);
		printed += ret;
		i++;
		if (ret == -1)
			return (-1);
	}
	va_end(args);
	return (printed);
}
