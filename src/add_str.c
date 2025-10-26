/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:11:32 by scambier          #+#    #+#             */
/*   Updated: 2024/12/05 17:26:09 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion_specification.h"

void	add_str(t_strb *buffer, t_conv_spec *spec, char *str)
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
		ft_strb_addstr(buffer, str, precise_size);
	ft_strb_setchars(buffer, ' ', ft_max(spec->field_width - precise_size, 0));
	if (!(spec->flags & LEFT_ALIGN))
		ft_strb_addstr(buffer, str, precise_size);
}
