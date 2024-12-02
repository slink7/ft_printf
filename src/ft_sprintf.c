/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:56:32 by scambier          #+#    #+#             */
/*   Updated: 2024/12/02 09:24:00 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

#include "conversion_specification.h"

char	*ft_vsprintf(const char	*format, va_list ap)
{
	t_conv_spec	spec;

	printf("Success : %d\n", read_conversion_specification(&spec, format, ap));
	printf("Flags : %d\n", spec.flags);
	printf("Field_width : %d\n", spec.field_width);
	printf("Precision : %d\n", spec.precision);
	printf("Specifier : %c\n", spec.specifier);
	printf("Length : %d\n", spec.length);
	return (0);
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