/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:06:41 by asyed             #+#    #+#             */
/*   Updated: 2023/10/27 15:06:42 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_subptr(unsigned long n)
{
	if (n >= 16)
	{
		ft_subptr(n / 16);
		ft_subptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_pf(n + '0');
		else
			ft_putchar_pf(n - 10 + 'a');
	}
}

int	ft_voidptr_pf(unsigned long p)
{
	int	len;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = write (1, "0x", 2);
	ft_subptr(p);
	while (p != 0)
	{
		len++;
		p = p / 16;
	}
	return (len);
}
