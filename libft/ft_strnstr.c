/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:09:27 by asyed             #+#    #+#             */
/*   Updated: 2023/09/11 10:09:28 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// locate first occurence of null terminater str little in big

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_i;
	size_t	lil_j;

	if (*little == 0)
		return ((char *)big);
	big_i = 0;
	while (big[big_i] && big_i < len)
	{
		lil_j = 0;
		while (big[big_i + lil_j] == little[lil_j] && (big_i + lil_j) < len)
		{
			if (little[lil_j + 1] == '\0')
				return ((char *)&big[big_i]);
			lil_j++;
		}
		big_i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*largestring = "Foo Bar Baz"; // large string
	const char	*smallstring = "Bar"; // substring to search
	char		*ptr; // Pointer to result

	// Search for 'smallstring' within the first 9 characters of 'largestring'
	ptr = ft_strnstr(largestring, smallstring, 9); 
	if (ptr != NULL)
	{
		printf("Found at position: %ld\n", ptr - largestring); 
		printf("Matched string: %s\n", ptr);
	}
	else
	{
		printf("Substring not found\n"); 
	}
	return (0);
}*/