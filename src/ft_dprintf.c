/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:02:44 by scambier          #+#    #+#             */
/*   Updated: 2025/10/26 23:38:31 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*temp;
	int		len;
	int		out;

	len = ft_vsprintf(&temp, format, ap);
	if (!temp)
		return (-1);
	out = write(fd, temp, len);
	free(temp);
	return (out);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		out;

	va_start(ap, format);
	out = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (out);
}
