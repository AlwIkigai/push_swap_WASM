/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:10:44 by asyed             #+#    #+#             */
/*   Updated: 2023/09/11 20:10:46 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
set a block of memory to zero. It takes two arguments: 
a pointer to the memory block.
the size (in bytes) of the block to be set to zero.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}
/*
#include <stdio.h>

int main(void)
{
	char buffer[20]; // Declare a character array.
	// Initialize the buffer with null characters.
	ft_bzero(buffer, sizeof(buffer));
	// Print the initial contents of the buffer.
	printf("Initial Contents: %s\n", buffer);
	// Use ft_bzero to zero out the entire buffer.
	ft_bzero(buffer, sizeof(buffer));
	// Print the modified contents of the buffer (should be all zeros).
	printf("Modified Contents: %s\n", buffer);
	return (0);
}
*/