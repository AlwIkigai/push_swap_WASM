/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:30:33 by asyed             #+#    #+#             */
/*   Updated: 2023/09/11 16:30:35 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Both functions help prevent buffer overflows/
// Ensure that the resulting strings are properly null-terminated.
// Used for copying one string into another.
// Ensures that the destination buffer doesn't overflow.
// Guarantees that the resulting string is null-terminated.

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char destination[5];
    char *source;

    source = "Hello, world!";

    // Print the source string.
    printf("Source: %s\n", source);
    size_t my_result = ft_strlcpy(destination, source, 5);

    // Print the copied string and its length.
    printf("Copied String: %s\n", destination);
    printf("My result length: %zu\n", my_result);

    return (0);
}

//	size_t true_result = strlcpy(destination, source, sizeof(destination));
//	printf("True result length: %zu\n", true_result);
*/