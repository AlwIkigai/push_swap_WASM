/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:43:09 by asyed             #+#    #+#             */
/*   Updated: 2023/09/07 16:43:15 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// find first letter searching for
// if char found, return the address of pointer
// if char == s[i] value. i = 0

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char) c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char	*str;
	char	search;
	char *result;

	str = "Hello\n Ahmad!";
	search = '\n';
	result = ft_strchr(str, search);
	
	if (result != NULL)
	{
		printf("Result =: %s\n", result);
	}
	else
	{
		printf("NULL\n");
	}
	return(0);
}
*/
