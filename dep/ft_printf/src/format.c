/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:59:23 by llapage           #+#    #+#             */
/*   Updated: 2023/05/23 11:02:31 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_format(char format, va_list args)
{
	if (format == 'c')
		return (print_c(va_arg(args, int)));
	if (format == 's')
		return (print_s(va_arg(args, char *)));
	if (format == 'p')
		return (print_p(va_arg(args, unsigned long long), 'x'));
	if (format == 'd')
		return (print_d(va_arg(args, int)));
	if (format == 'i')
		return (print_d(va_arg(args, int)));
	if (format == 'u')
		return (print_d(va_arg(args, unsigned int)));
	if (format == 'x')
		return (print_x(va_arg(args, unsigned int), 'x'));
	if (format == 'X')
		return (print_x(va_arg(args, unsigned int), 'X'));
	if (format == '%')
		return (print_c('%'));
	return (-1);
}
