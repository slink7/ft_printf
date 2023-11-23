/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:19:17 by scambier          #+#    #+#             */
/*   Updated: 2023/11/23 22:25:27 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_putters.h"

int	ft_putstr(va_list p)
{
	char	*c;

	c = va_arg(p, char *);
	if (c == 0)
		return (write(STDOUT, "(null)", 6));
	return (write(STDOUT, c, ft_strlen(c)));
}
