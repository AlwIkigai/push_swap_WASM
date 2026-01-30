/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:30:18 by asyed             #+#    #+#             */
/*   Updated: 2023/10/26 17:30:20 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n, int base)
{
	long	nbl;
	int		count;

	nbl = n;
	count = 0;
	if (nbl < 0)
	{
		ft_putchar_pf('-');
		nbl *= -1;
		count++;
	}
	if (nbl < base)
	{
		ft_putchar_pf(nbl + '0');
		count++;
	}
	else
	{
		count += ft_putnbr_pf(nbl / base, base);
		count += ft_putnbr_pf(nbl % base, base);
	}
	return (count);
}
