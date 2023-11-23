/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:27:35 by scambier          #+#    #+#             */
/*   Updated: 2023/11/23 21:42:30 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_putters.h"

int	ft_puthexu(va_list p)
{
	return (ft_putnbr_base(va_arg(p, int), "0123456789ABCDEF", 1));
}
