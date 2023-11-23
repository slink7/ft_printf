/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:50:39 by scambier          #+#    #+#             */
/*   Updated: 2023/11/23 18:55:55 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(va_list p)
{
	char c = va_arg(p, int);
	printf("%c", c);
	return (0);
}
int	ft_putstr(va_list p)
{
	char *str = va_arg(p, char *);
	printf("%s", str);
	return (0);
}
int	ft_putptr(va_list p)
{
	void *ptr = va_arg(p, void *);
	printf("%p", ptr);
	return (0);
}
int	ft_putnbr(va_list p)
{
	int	c = va_arg(p, int);
	printf("%d", c);
	return (0);
}

int	ft_putunsigned(va_list p)
{
	unsigned int	c = va_arg(p, unsigned int);
	printf("%u", c);
	return (0);
}

int	ft_puthexl(va_list p)
{
	int	c = va_arg(p, int);
	printf("%x", c);
	return (0);
}

int	ft_puthexu(va_list p)
{
	int	c = va_arg(p, int);
	printf("%X", c);
	return (0);
}

int	ft_putpercent(va_list p)
{
	(void)p;
	printf("%%");
	return (0);
}

typedef struct s_format {
	char c;
	int (*f)(va_list p);
} t_format;

int	associate(char c, va_list p)
{
	static t_format formats[] = {
		(t_format) { 'c', ft_putchar },
		(t_format) { 's', ft_putstr },
		(t_format) { 'p', ft_putptr },
		(t_format) { 'd', ft_putnbr },
		(t_format) { 'i', ft_putnbr },
		(t_format) { 'u', ft_putunsigned },
		(t_format) { 'x', ft_puthexl },
		(t_format) { 'X', ft_puthexu },
		(t_format) { '%', ft_putpercent },
	};
	int	k;

	k = 9;
	while (--k >= 0)
		if (formats[k].c == c)
			return (formats[k].f(p));
	printf("%%%c", c);
	return (2);
}

void	ft_printf(char *format, ...)
{
	va_list p;
	va_start(p, format);
	while (*format)
	{
		if (*format != '%')
		{
			printf("%c", *format);
			format++;
			continue ;
		}
		format++;
		associate(*format, p);
		format++;
	}
}
