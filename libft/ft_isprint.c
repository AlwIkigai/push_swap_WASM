/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:21:57 by asyed             #+#    #+#             */
/*   Updated: 2023/09/07 12:21:58 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
/*

#include <stdio.h>

int	main(void)

{
	char	p;
	char	np;

	p = 98;
	np = 31;

	printf("%c is printable\n", p);
	printf("%c is NOT printable\n", np);
	return (0);
}*/