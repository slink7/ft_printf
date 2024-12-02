/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:40:28 by scambier          #+#    #+#             */
/*   Updated: 2024/12/02 09:27:18 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_SPECIFICATION
# define CONVERSION_SPECIFICATION

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

void	init_conv_spec(t_conv_spec *out);
int		flag_predicat(char c);
int		read_flags(t_conv_spec *out, const char *str, int *k);
int		read_number(int	*out, const char *str, int *k, va_list va);
int		read_conversion_specification(t_conv_spec *out, const char *str, va_list va);

#endif