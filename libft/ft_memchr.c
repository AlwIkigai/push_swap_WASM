/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:55:36 by asyed             #+#    #+#             */
/*   Updated: 2023/09/14 20:30:08 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// scans inintial n byte if memory area pointed by for the first instance of c
// find first character

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
		{
			return ((void *)p);
		}
		p++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
    const char *str = "Hello, World!";
    char target = 'W';
    size_t n = 13;
    // Length of the string "Hello, World!"
    // (excluding the null terminator)

    const char *ft_result = ft_memchr(str, target, n);
    if (ft_result != NULL) {
        printf("Found '%c' at position %ld\n", target, ft_result - str);
    } else {
        printf("'%c' not found in the string\n", target);
    }
    return (0);
}*/
