/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:56:32 by scambier          #+#    #+#             */
/*   Updated: 2024/12/03 19:07:26 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

#include "libft.h"
#include "conversion_specification.h"

void	add_char(t_strbuilder *buffer, t_conv_spec *spec, char c);
void	add_str(t_strbuilder *buffer, t_conv_spec *spec, char *str);

typedef struct	s_base {
	char			*digits;
	unsigned int	size;
}	t_base;

int	ft_nbrlen(unsigned int n, unsigned int base)
{
	int	out;

	out = 0;
	while (n)
	{
		n /= base;
		out++;
	}
	return (out);
}

void	add_int_base_rec(t_strbuilder *buffer, unsigned int value, t_base *base)
{
	if (!value)
		return ;
	add_int_base_rec(buffer, value / base->size, base);
	ft_strbuilder_addchar(buffer, base->digits[value % base->size]);
}

void	add_int_base(t_strbuilder *buffer, unsigned int value, t_base *base, int precision)
{
	int	nbrlen;
	int	k;

	nbrlen = ft_nbrlen(value, base->size);
	k = -1;
	while (++k < (precision - nbrlen))
		ft_strbuilder_addchar(buffer, base->digits[0]);
	add_int_base_rec(buffer, value, base);
}

void	add_int(t_strbuilder *buffer, t_conv_spec *spec, int value)
{
	static t_base base = {"0123456789", 10u};

	(void) spec;
	if (!value)
		ft_strbuilder_addchar(buffer, '0');
	else
	{
		if (spec->precision == -1)
			spec->precision = 1;
		if (value < 0)
		{
			ft_strbuilder_addchar(buffer, '-');
			if (value / 10 < 0)
				add_int_base(buffer, -(value / 10), &base, spec->precision - 1);
			ft_strbuilder_addchar(buffer, base.digits[- (value % 10)]);
		}
		else
			add_int_base(buffer, value, &base, spec->precision);
	}
}

void	add_unsigned(t_strbuilder *buffer, t_conv_spec *spec, unsigned int value)
{
	static t_base base = {"0123456789", 10u};

	(void) spec;
	if (spec->precision == -1)
		spec->precision = 1;
	if (spec->flags & LEFT_ALIGN)
		add_int_base(buffer, value, &base, spec->precision);
	for (int k = 0; k < spec->field_width - ft_max(ft_nbrlen(value, 10), spec->precision); k++)
		ft_strbuilder_addchar(buffer, ' ');
	if (!(spec->flags & LEFT_ALIGN))
		add_int_base(buffer, value, &base, spec->precision);
}

static void	handle_specification(t_strbuilder *buffer, t_conv_spec *spec, va_list ap)
{
	if (spec->specifier == 's')
		add_str(buffer, spec, va_arg(ap, char *));
	else if (spec->specifier == 'd' || spec->specifier == 'i')
		add_int(buffer, spec, va_arg(ap, int));
	else if (spec->specifier == 'c')
		add_char(buffer, spec, (char) va_arg(ap, int));
	else if (spec->specifier == 'u')
		add_unsigned(buffer, spec, va_arg(ap, unsigned int));
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