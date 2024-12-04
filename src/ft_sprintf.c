/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:56:32 by scambier          #+#    #+#             */
/*   Updated: 2024/12/04 02:49:55 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

#include "libft.h"
#include "conversion_specification.h"

void	add_char(t_strbuilder *buffer, t_conv_spec *spec, char c);
void	add_str(t_strbuilder *buffer, t_conv_spec *spec, char *str);
void	add_unsigned(t_strbuilder *buffer, t_conv_spec *spec, unsigned int value, unsigned int bi);
void	add_int(t_strbuilder *buffer, t_conv_spec *spec, int value);

static void	handle_specification(t_strbuilder *buffer, t_conv_spec *spec, va_list ap)
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
	else if (spec->specifier == '%')
		ft_strbuilder_addchar(buffer, '%');
}

char	*ft_vsprintf(const char	*format, va_list ap)
{
	t_conv_spec		spec;
	t_strbuilder	*buffer;
	char			*next_spec;
	char			*out;

	buffer = ft_strbuilder_new();
	if (!buffer)
		return (0);
	next_spec = ft_strchr(format, '%');
	while (next_spec)
	{
		ft_strbuilder_addstr(buffer, (char *)format, (int)(next_spec - format));
		if (read_conversion_specification(&spec, next_spec, ap))
			handle_specification(buffer, &spec, ap);
		format = next_spec + spec.length;
		next_spec = ft_strchr(format, '%');
	}
	ft_strbuilder_addstr(buffer, (char *)format, ft_strlen(format));
	out = ft_strbuilder_build(buffer);
	ft_strbuilder_free(&buffer);
	return (out);
}

char	*ft_sprintf(const char	*format, ...)
{
	va_list	ap;
	char	*out;

	va_start(ap, format);
	out = ft_vsprintf(format, ap);
	va_end(ap);
	return (out);
}
