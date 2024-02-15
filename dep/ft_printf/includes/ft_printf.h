/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:59:03 by llapage           #+#    #+#             */
/*   Updated: 2023/05/23 16:41:23 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		print_format(char format, va_list args);
int		print_c(char c);
int		print_s(char *s);
int		print_p(unsigned long long ptr, char f);
int		print_d(long long n_arg);
int		put_addr(unsigned long long ptr, char f);
int		print_x(unsigned long long ptr, char f);
int		addr_len(unsigned long long ptr);
char	*ft_itoa_l(long long n);
char	*ft_itoa_16(long long n, char f);

#endif
