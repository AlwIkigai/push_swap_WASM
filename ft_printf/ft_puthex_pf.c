/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:06:19 by asyed             #+#    #+#             */
/*   Updated: 2023/10/27 13:06:21 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int n, char specifier)

{
	long	nbl;
	char	*hexdigits;
	int		count;

	nbl = n;
	count = 0;
	if (specifier == 'x')
		hexdigits = "0123456789abcdef";
	else if (specifier == 'X')
		hexdigits = "0123456789ABCDEF";
	if (nbl < 16)
	{
		ft_putchar_pf(hexdigits[nbl]);
		count++;
	}
	else
	{
		count += ft_puthex_pf(nbl / 16, specifier);
		count += ft_puthex_pf(nbl % 16, specifier);
	}
	return (count);
}
