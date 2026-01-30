/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:46:01 by asyed             #+#    #+#             */
/*   Updated: 2023/09/14 17:28:35 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
void *s: pointer to the memory block fill with a specific value.
int c: The value set in each byte of the memory block. 
Typically an integer.
Internally converted to an unsigned char 
before being written to the memory block.
size_t n: 
The number of bytes to set to the specified value.
starting from the memory location pointed to by s.

Purpose
Initialize a memory block to a specific value, 
often used to initialize arrays, buffers, or data structures to a known state.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	uc;

	p = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n > 0)
	{
		*p = uc;
		p++;
		n--;
	}
	return (s);
}
/* space for 20, 10 byte memory set

#include <stdio.h>
#include <string.h>

int main(void)
{
    // Declare a character array.
    char buffet[20];
    char buffer[20];

    // Print the initial contents of the buffer.
    printf("Initial Actual Contents: %s\n", buffet);
    printf("Initial My Contents: %s\n", buffer);
    // to fill the first 10 bytes of the buffer with 'x'.
    memset(buffer, 'x', 10);
    ft_memset(buffer, 'x', 10);
    // Print the modified contents of the buffer.
    printf("Modified Actual Contents: %s\n", buffer);
    printf("Modified My Contents: %s\n", buffer);

    return (0);
}
*/
