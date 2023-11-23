/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scambier <scambier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:23:18 by scambier          #+#    #+#             */
/*   Updated: 2023/11/23 22:26:32 by scambier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_putters.h"

static int	is_base_valid(char *base)
{
	int	k;
	int	l;

	k = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[k])
	{
		l = 0;
		while (base[l])
		{
			if (l != k && base[k] == base[l])
				return (0);
			l++;
		}
		if (base[k] == '+' || base[k] == '-')
			return (0);
		k++;
	}
	return (1);
}

int	ft_putnbr_base_signed(long nbr, char *base)
{
	int			ibase;
	long int	cast;
	int			out;

	if (!is_base_valid(base))
		return (0);
	ibase = ft_strlen(base);
	cast = nbr;
	out = 0;
	if (cast < 0)
	{
		out += write(STDOUT, "-", 1);
		cast *= -1;
	}
	if (cast > ibase - 1)
		out += ft_putnbr_base_signed(cast / ibase, base);
	out += write(STDOUT, base + (cast % ibase), 1);
	return (out);
}

int	ft_putnbr_base_unsigned(unsigned long nbr, char *base)
{
	unsigned int		ibase;
	long unsigned int	cast;
	int					out;

	out = 0;
	if (!is_base_valid(base))
		return (0);
	ibase = ft_strlen(base);
	cast = nbr;
	if (cast > ibase - 1)
		out += ft_putnbr_base_unsigned(cast / ibase, base);
	out += write(STDOUT, base + (cast % ibase), 1);
	return (out);
}

int	ft_putnbr_base(long n, char *base, int signe)
{
	if (signe)
		return (ft_putnbr_base_signed(n, base));
	else
		return (ft_putnbr_base_unsigned(n, base));
}
