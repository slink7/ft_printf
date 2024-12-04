/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:10:18 by scambier          #+#    #+#             */
/*   Updated: 2024/12/04 02:51:19 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion_specification.h"

void	add_char(t_strbuilder *buffer, t_conv_spec *spec, char c)
{
	if (!c)
		return ;
	if (spec->flags & LEFT_ALIGN)
		ft_strbuilder_addchar(buffer, c);
	for (int k = 0; k < ft_max(spec->field_width - 1, 0); k++)
		ft_strbuilder_addchar(buffer, ' ');
	if (!(spec->flags & LEFT_ALIGN))
		ft_strbuilder_addchar(buffer, c);
}
