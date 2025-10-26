/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:10:18 by scambier          #+#    #+#             */
/*   Updated: 2025/10/26 17:55:37 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion_specification.h"

void	add_char(t_strb *buffer, t_conv_spec *spec, char c)
{
	if (!(spec->flags & LEFT_ALIGN))
		ft_strb_setchars(buffer, ' ', ft_max(spec->field_width - 1, 0));
	ft_strb_addchar(buffer, c);
	if (spec->flags & LEFT_ALIGN)
		ft_strb_setchars(buffer, ' ', ft_max(spec->field_width - 1, 0));
}
