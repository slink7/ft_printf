/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:28:00 by scambier          #+#    #+#             */
/*   Updated: 2023/11/23 22:49:37 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_putters.h"

int	ft_putptr(va_list p)
{
	long	ptr;

	ptr = va_arg(p, long);
	if (!ptr)
		return (write(STDOUT, "(nil)", 5));
	return (write(STDOUT, "0x", 2)
		+ ft_putnbr_base(ptr, "0123456789abcdef", 0));
}
