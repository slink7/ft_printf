/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:15:37 by scambier          #+#    #+#             */
/*   Updated: 2025/10/26 17:52:50 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"

int	ft_vsprintf(char **out, const char *format, va_list ap);
int	ft_sprintf(char **out, const char *format, ...);

int	ft_vdprintf(int fd, const char *format, va_list ap);
int	ft_dprintf(int fd, const char *format, ...);

int	ft_vprintf(const char *format, va_list ap);
int	ft_printf(const char *format, ...);

#endif