/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:40:28 by scambier          #+#    #+#             */
/*   Updated: 2024/12/04 02:50:11 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_SPECIFICATION_H
# define CONVERSION_SPECIFICATION_H

# include <stdarg.h>

# define PREFIX		0b00001
# define ZERO_PAD	0b00010
# define LEFT_ALIGN	0b00100
# define SPACE		0b01000
# define SIGNED		0b10000

typedef struct s_conv_spec {
	char	flags;
	int		field_width;
	int		precision;
	char	specifier;
	int		length;
}	t_conv_spec;

int		read_conversion_specification(t_conv_spec *out, const char *str, va_list va);

#endif