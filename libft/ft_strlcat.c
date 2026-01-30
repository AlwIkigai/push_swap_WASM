/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:51:13 by asyed             #+#    #+#             */
/*   Updated: 2023/09/13 21:34:50 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Both functions help prevent buffer overflows
// Ensure that the resulting strings are properly null-terminated.
// Used for concatenating one string to the end of another.
// Prevents buffer overflows by limiting the size of the operation.
// Ensures that the resulting concatenated string is null-terminated.

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = dst_len;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>

int main(void)
{
    char destination[20] = "Hello, ";
    char source[] = "world!";

    // Print the original destination and source strings.
    printf("Original Destination: %s\n", destination);
    printf("Source: %s\n", source);

    // Call the strlcat function
    // Concatenate the source string to the destination string.
    size_t result = ft_strlcat(destination, source, sizeof(destination));

    // Print the concatenated string and its length.
    printf("Concatenated String: %s\n", destination);
    printf("Resulting Length: %zu\n", result);

    return (0);
}
*/