/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:55:08 by asyed             #+#    #+#             */
/*   Updated: 2023/10/27 11:55:09 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_pf(unsigned int n, int base)
{
	long	nbl;
	int		count;

	nbl = n;
	count = 0;
	if (n == 0)
	{
		ft_putchar_pf('0');
		return (1);
	}
	if (nbl < base)
	{
		ft_putchar_pf(nbl + '0');
		count++;
	}
	else
	{
		count += ft_putunbr_pf(nbl / base, base);
		count += ft_putunbr_pf(nbl % base, base);
	}
	return (count);
}
