/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:10:18 by scambier          #+#    #+#             */
/*   Updated: 2024/12/04 18:35:05 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion_specification.h"

void	add_char(t_strbuilder *buffer, t_conv_spec *spec, char c)
{
	if (!(spec->flags & LEFT_ALIGN))
		for (int k = 0; k < ft_max(spec->field_width - 1, 0); k++)
			ft_strbuilder_addchar(buffer, ' ');
	if (!c)
		ft_strbuilder_addchar(buffer, '\006');
	else
		ft_strbuilder_addchar(buffer, c);
	if (spec->flags & LEFT_ALIGN)
		for (int k = 0; k < ft_max(spec->field_width - 1, 0); k++)
			ft_strbuilder_addchar(buffer, ' ');
}
