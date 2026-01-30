/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:41:10 by asyed             #+#    #+#             */
/*   Updated: 2023/09/12 17:41:12 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copies n byte from memory area
// src to dest
// may overlap
// non-overlapping memory areas, can copy forward
// overlapping memory areas, copy backward to avoid corruption

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *) src;
	if (d == s || n == 0)
		return (dest);
	if (d < s || d >= (s + n))
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *src;
	char dest[20];

	src = "this is a test";
	ft_memmove(dest, src, 14);
	printf("result: %s\n", dest);
	return (0);
}*/