/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:18:26 by scambier          #+#    #+#             */
/*   Updated: 2024/12/04 01:46:43 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion_specification.h"

typedef struct	s_base {
	char			*digits;
	unsigned int	size;
	char			*prefix;
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

// void	add_int(t_strbuilder *buffer, t_conv_spec *spec, int value)
// {
// 	static t_base base = {"0123456789", 10u};

// 	(void) spec;
// 	if (!value)
// 		ft_strbuilder_addchar(buffer, '0');
// 	else
// 	{
// 		if (spec->precision == -1)
// 			spec->precision = 1;
// 		if (value < 0)
// 		{
// 			ft_strbuilder_addchar(buffer, '-');
// 			if (value / 10 < 0)
// 				add_int_base(buffer, -(value / 10), &base, spec->precision - 1);
// 			ft_strbuilder_addchar(buffer, base.digits[- (value % 10)]);
// 		}
// 		else
// 			add_int_base(buffer, value, &base, spec->precision);
// 	}
// }

#include <stdio.h>

void	add_unsigned(t_strbuilder *buffer, t_conv_spec *spec, unsigned int value, unsigned int bi)
{
	static t_base	bases[] = {
		{"0123456789", 10u, ""},
		{"0123456789abcdef", 16u, "0x"},
		{"0123456789ABCDEF", 16u, "0X"}
	};
	int				number_len;
	char			padding;

	padding = ' ' + !!(spec->flags & ZERO_PAD) * ('0' - ' ');
	number_len = ft_max(ft_nbrlen(value, bases[bi].size), spec->precision);
	if (spec->flags & PREFIX && spec->flags & PREFIX)
		number_len += ft_strlen(bases[bi].prefix);
	if (spec->precision == -1)
		spec->precision = 1;
	if (spec->flags & ZERO_PAD && spec->flags & PREFIX)
		ft_strbuilder_addstr(buffer, bases[bi].prefix, ft_strlen(bases[bi].prefix));
	if (!(spec->flags & LEFT_ALIGN))
		for (int k = 0; k < spec->field_width - number_len; k++)
			ft_strbuilder_addchar(buffer, padding);
	if ((spec->flags & PREFIX) && !(spec->flags & ZERO_PAD))
		ft_strbuilder_addstr(buffer, bases[bi].prefix, ft_strlen(bases[bi].prefix));
	add_int_base(buffer, value, bases + bi, spec->precision);
	if ((spec->flags & LEFT_ALIGN))
		for (int k = 0; k < spec->field_width - number_len; k++)
			ft_strbuilder_addchar(buffer, padding);
}