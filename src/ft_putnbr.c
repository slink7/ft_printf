/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:56:12 by scambier          #+#    #+#             */
/*   Updated: 2023/11/23 21:03:51 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_putters.h"

int	ft_putnbr(va_list p)
{
	return (ft_putnbr_base(va_arg(p, int), "0123456789", 1));
}
