/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:33:43 by asyed             #+#    #+#             */
/*   Updated: 2023/09/07 12:33:45 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
/*

#include <stdio.h>

int	main(void)
{
	char	a;
	int	na;

	a = 65;
	na = 129;

	printf("%c is ascii\n", a);
	printf("%c is NOT ascii\n", na);
	return (0);
}*/