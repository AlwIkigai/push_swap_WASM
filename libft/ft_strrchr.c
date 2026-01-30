/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:45:11 by asyed             #+#    #+#             */
/*   Updated: 2023/09/07 21:45:13 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// find last occurence of character
// go to end of the string first

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s)+1;
	while (len != 0)
	{
		len--;
		if (s[len] == (char)c)
			return ((char *)&s[len]);
	}
	if ((char) c == s[len])
		return ((char *)&s[len]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	const char	*str = "Hello, world";
	char	search = 'd';
	char *result = ft_strrchr(str, search);
	char *trueresult = strrchr(str, search);

	printf("my result =: %s\n", result);
	printf("actual result =: %s\n", trueresult);

	if (result != NULL)
	{
		printf("my found %c at position %ld\n", search, result - str); 
		printf("actual found %c at position %ld\n", search, trueresult - str); 
	}
	else
		printf("%c not found in the string.\n", search);
	return(0);
}*/