/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:50:39 by scambier          #+#    #+#             */
/*   Updated: 2023/11/23 22:52:19 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_putters.h"
#include "../ft_printf.h"

int	associate(char c, va_list p)
{
	static t_format	formats[] = {
		(t_format){'c', ft_putchar},
		(t_format){'s', ft_putstr},
		(t_format){'p', ft_putptr},
		(t_format){'d', ft_putnbr},
		(t_format){'i', ft_putnbr},
		(t_format){'u', ft_putunsigned},
		(t_format){'x', ft_puthexl},
		(t_format){'X', ft_puthexu},
		(t_format){'%', ft_putpercent},
	};
	int				k;

	k = 9;
	while (--k >= 0)
		if (formats[k].c == c)
			return (formats[k].f(p));
	write(STDOUT, "%", 1);
	write(STDOUT, &c, 1);
	return (2);
}

int	ft_printf(const char *format, ...)
{
	int		out;
	va_list	p;

	va_start(p, format);
	out = 0;
	while (*format)
	{
		if (*format != '%')
		{
			out += write(STDOUT, format++, 1);
			continue ;
		}
		format++;
		out += associate(*format++, p);
	}
	return (out);
}
