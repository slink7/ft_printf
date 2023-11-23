/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:00:09 by scambier          #+#    #+#             */
/*   Updated: 2023/11/23 22:33:28 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTTERS_H
# define FT_PUTTERS_H

# include <stdarg.h>

# define STDOUT 1

int	ft_strlen(char *str);
int	ft_putnbr_base(long n, char *base, int signe);

int	ft_putchar(va_list p);
int	ft_putstr(va_list p);
int	ft_putptr(va_list p);
int	ft_putnbr(va_list p);
int	ft_putunsigned(va_list p);
int	ft_puthexl(va_list p);
int	ft_puthexu(va_list p);
int	ft_putpercent(va_list p);

#endif