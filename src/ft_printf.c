/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:50:39 by scambier          #+#    #+#             */
/*   Updated: 2024/12/01 18:07:56 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

#include "conversion_specification.h"
#include "libft.h"

int	ft_printf(char *format, ...)
{
	va_list ap;
	t_conv_spec	spec;
	
	va_start(ap, format);
	init_conv_spec(&spec);
	printf("Success : %d\n", read_conversion_specification(&spec, format, ap));
	printf("Flags : %d\n", spec.flags);
	printf("Field_width : %d\n", spec.field_width);
	printf("Precision : %d\n", spec.precision);
	printf("Specifier : %c\n", spec.specifier);
	printf("Length : %d\n", spec.length);
	return (1);
}
