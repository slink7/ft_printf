/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:56:32 by scambier          #+#    #+#             */
/*   Updated: 2024/12/02 23:23:10 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

#include "libft.h"
#include "conversion_specification.h"

void	add_char(t_strbuilder *buffer, t_conv_spec *spec, char c)
{
	(void) spec;
	if (!c)
		return ;

	if (spec->flags & LEFT_ALIGN)
		ft_strbuilder_addchar(buffer, c);
	for (int k = 0; k < ft_max(spec->field_width - 1, 0); k++)
		ft_strbuilder_addchar(buffer, ' ');
	if (!(spec->flags & LEFT_ALIGN))
		ft_strbuilder_addchar(buffer, c);
}

void	add_int(t_strbuilder *buffer, t_conv_spec *spec, int value)
{
	(void) buffer;
	(void) spec;
	(void) value;
}

void	add_str(t_strbuilder *buffer, t_conv_spec *spec, char *str)
{
	int	precise_size;

	if (spec->precision == -1)
		spec->precision = 0x7FFFFFFF;
	if (!str && spec->precision > 5)
		str = "(null)";
	else if (!str)
		str = "";
	precise_size = ft_min(ft_strlen(str), spec->precision);
	if (spec->flags & LEFT_ALIGN)
		ft_strbuilder_addstr(buffer, str, precise_size);
	for (int k = 0; k < ft_max(spec->field_width - precise_size, 0); k++)
		ft_strbuilder_addchar(buffer, ' ');
	if (!(spec->flags & LEFT_ALIGN))
		ft_strbuilder_addstr(buffer, str, precise_size);
}

static void	handle_specification(t_strbuilder *buffer, t_conv_spec *spec, va_list ap)
{
	if (spec->specifier == 's')
		add_str(buffer, spec, va_arg(ap, char *));
	else if (spec->specifier == 'd' || spec->specifier == 'i')
		add_int(buffer, spec, va_arg(ap, int));
	else if (spec->specifier == 'c')
		add_char(buffer, spec, (char) va_arg(ap, int));
	else if (spec->specifier == '%')
		ft_strbuilder_addchar(buffer, '%');
	(void) spec;
	(void) ap;
	//ft_strbuilder_addstr(buffer, "CONVSPEC", 8);
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
	// printf("Success : %d\n", read_conversion_specification(&spec, format, ap));
	// printf("Flags : %d\n", spec.flags);
	// printf("Field_width : %d\n", spec.field_width);
	// printf("Precision : %d\n", spec.precision);
	// printf("Specifier : %c\n", spec.specifier);
	// printf("Length : %d\n", spec.length);
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