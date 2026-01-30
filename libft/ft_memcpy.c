/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:29:01 by asyed             #+#    #+#             */
/*   Updated: 2023/09/14 19:57:16 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* dest:
A pointer to the destination memory block where you want to copy the data.
src:
A pointer to the source memory block from which you want to copy the data.
n:
number of bytes to copy from the source to the destination.

byte-by-byte copy of n bytes from the source to the destination
copying raw binary data, structures, arrays, or any other data in memory.
copies n bytes from memory area src to memory area dest.  
memory areas must not overlap
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s && d < s + n)
		return (NULL);
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    char source[] = "Hello, memcpy!"; // Source string.
    char destination[20];            // Destination buffer.
    // Copy the source string to the destination buffer using ft_memcpy.
    ft_memcpy(destination, source, sizeof(source));
    // Print the contents of the destination buffer.
    printf("Destination: %s\n", destination);
    return (0);
}*/
