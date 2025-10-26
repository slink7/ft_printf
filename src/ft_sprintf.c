/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:56:32 by scambier          #+#    #+#             */
/*   Updated: 2025/10/27 00:05:12 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

#include "libft.h"
#include "conversion_specification.h"

void	add_char(t_strb *buffer, t_conv_spec *spec, char c);
void	add_str(t_strb *buffer, t_conv_spec *spec, char *str);
void	add_unsigned(t_strb *buffer, t_conv_spec *spec, unsigned int value, unsigned int bi);
void	add_int(t_strb *buffer, t_conv_spec *spec, int value);
void	add_pointer(t_strb *buffer, t_conv_spec *spec, unsigned long value);

static void	handle_specification(t_strb *buffer, t_conv_spec *spec, va_list ap)
{
	if (spec->specifier == 's')
		add_str(buffer, spec, va_arg(ap, char *));
	else if (spec->specifier == 'd' || spec->specifier == 'i')
		add_int(buffer, spec, va_arg(ap, int));
	else if (spec->specifier == 'c')
		add_char(buffer, spec, (char) va_arg(ap, int));
	else if (spec->specifier == 'u')
		add_unsigned(buffer, spec, va_arg(ap, unsigned int), 0);
	else if (spec->specifier == 'x')
		add_unsigned(buffer, spec, va_arg(ap, unsigned int), 1);
	else if (spec->specifier == 'X')
		add_unsigned(buffer, spec, va_arg(ap, unsigned int), 2);
	else if (spec->specifier == 'p')
		add_pointer(buffer, spec, va_arg(ap, unsigned long));
	else if (spec->specifier == '%')
		ft_strb_addchar(buffer, '%');
	else {
		ft_strb_addchar(buffer, '%');
		spec->length = 1;
	}
}

int	ft_vsprintf(char **out, const char	*format, va_list ap)
{
	t_conv_spec		spec;
	t_strb	*buffer;
	char			*next_spec;
	unsigned int	out_len;

	buffer = ft_strb_new();
	if (!buffer)
		return (0);
	next_spec = ft_strchr(format, '%');
	while (next_spec)
	{
		ft_strb_addstr(buffer, (char *)format, (int)(next_spec - format));
		read_conversion_specification(&spec, next_spec, ap);
		handle_specification(buffer, &spec, ap);
		format = next_spec + spec.length;
		next_spec = ft_strchr(format, '%');
	}
	ft_strb_addstr(buffer, (char *)format, ft_strlen(format));
	*out = ft_strb_build(buffer);
	out_len = ft_strb_len(buffer);
	ft_strb_free(&buffer);
	return (out_len);
}

int	ft_sprintf(char **out, const char *format, ...)
{
	va_list	ap;
	size_t	out_len;

	va_start(ap, format);
	out_len = ft_vsprintf(out, format, ap);
	va_end(ap);
	return (out_len);
}
