/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:20:15 by asyed             #+#    #+#             */
/*   Updated: 2023/09/14 21:08:40 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// compares first n byte of memory s1 & s2
// size_t n = 16; // Number of BYTES to compare

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stddef.h>

int main(void)
{
    // Define two memory areas to compare
    unsigned char memory1[] = {0x41, 0x42, 0x43, 0x44};
    // ASCII values 'A', 'B', 'C', 'D'
    unsigned char memory2[] = {0x41, 0x42, 0x43, 0x45};
    // ASCII values 'A', 'B', 'C', 'E'

    // int memory1[] = {1, 2, 3, 4, 5}; // ASCII values 'A', 'B', 'C', 'D'
    // int memory2[] = {1, 2, 9, 4, 5}; // ASCII values 'A', 'B', 'C', 'E'

    size_t n = 16; // Number of BYTES to compare

    // Call the custom ft_memcmp function to compare the memory areas
    int result = ft_memcmp(memory1, memory2, n);

    if (result < 0) 
    {
        // Print a message indicating memory1 is less than memory2
        printf("memory1 is less than memory2\n");
    } 
    else if (result == 0) 
    {
        // Print a message indicating memory1 is equal to memory2
        printf("memory1 is equal to memory2\n");
    } 
    else 
    {
        // Print a message indicating memory1 is greater than memory2
        printf("memory1 is greater than memory2\n");
    }
    return (0);
}
*/
