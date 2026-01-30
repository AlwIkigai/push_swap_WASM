/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:17:50 by asyed             #+#    #+#             */
/*   Updated: 2023/09/20 15:17:51 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar_fd('-', fd);
		nbl *= -1;
	}
	if (nbl < 10)
		ft_putchar_fd(nbl + '0', fd);
	else
	{
		ft_putnbr_fd(nbl / 10, fd);
		ft_putnbr_fd(nbl % 10, fd);
	}
}

/*
#include <stdio.h>

int main(void)
{
    int num = 12345;
    int fd = STDOUT_FILENO;

    ft_putnbr_fd(num, fd);
    ft_putchar_fd('\n', fd);

    return (0);
}
*/