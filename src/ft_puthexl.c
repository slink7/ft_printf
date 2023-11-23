/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:26:48 by scambier          #+#    #+#             */
/*   Updated: 2023/11/23 21:43:28 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_putters.h"

int	ft_puthexl(va_list p)
{
	return (ft_putnbr_base(va_arg(p, int), "0123456789abcdef", 1));
}
