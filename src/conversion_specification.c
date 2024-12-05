/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:39:56 by scambier          #+#    #+#             */
/*   Updated: 2024/12/05 01:14:48 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion_specification.h"

static void	init_conv_spec(t_conv_spec *out)
{
	ft_memset(out, 0, sizeof(t_conv_spec));
	out->precision = -1;
}

static int	flag_predicat(char c)
{
	const char	*flags = "#0- +";
	char		*out;

	out = ft_strchr(flags, c);
	if (out)
		return (out - flags + 1);
	return (0);
}

static int	read_flags(t_conv_spec *out, const char *str, int *k)
{
	int	temp;

	temp = flag_predicat(str[*k]);
	while (temp && ((*k)++))
	{
		out->flags |= 1 << (temp - 1);
		temp = flag_predicat(str[*k]);
	}
	if (out->flags & LEFT_ALIGN)
		out->flags &= ~ZERO_PAD;
	if (out->flags & SIGNED)
		out->flags &= ~SPACE;
	return (1);
}

static int	read_number(int	*out, const char *str, int *k, va_list ap)
{
	int	offset;

	if (str[*k] == '*' && ((*k)++))
	{
		*out = va_arg(ap, int);
		return (1);
	}
	*out = 0;
	offset = str[*k] - '0';
	while (offset >= 0 && offset <= 9 && ((*k)++))
	{
		*out = *out * 10 + offset;
		offset = str[*k] - '0';
	}
	return (1);
}

int	read_conversion_specification(t_conv_spec *out, const char *str, va_list ap)
{
	int		k;
	char	*temp;

	k = 0;
	if (str[k++] != '%')
		return (0);
	init_conv_spec(out);
	read_flags(out, str, &k);
	read_number(&out->field_width, str, &k, ap);
	if (str[k] == '.' && k++)
		read_number(&out->precision, str, &k, ap);
	temp = ft_strchr("cspdiuxX%", str[k++]);
	if (!temp)
		return (0);
	out->specifier = *temp;
	out->length = k;
	if (out->precision != -1)
		out->flags &= ~ZERO_PAD;
	return (1);
}
