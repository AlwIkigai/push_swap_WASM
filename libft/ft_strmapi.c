/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:42:23 by asyed             #+#    #+#             */
/*   Updated: 2023/09/20 19:42:24 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function 'f' to each character of the string 's',
** creating a new string resulting from successive applications of 'f'.
**
** Parameters:
**   s: The string on which to iterate.
**   f: The function to apply to each character. It takes two arguments:
**      - 'unsigned int' index: The index of the character in 's'.
**      - 'char' c: The character from 's'.
**
** Return Value:
**   The new string created from the successive applications of 'f'.
**   Returns NULL if the allocation fails.
*/
// "Hello, World" &map function -> isupper = "HELLO, WORLD"

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	if (s == NULL)
		return (NULL);
	res = (char *)malloc(ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
char ft_toupper_wrapper(unsigned int index, char c)
{
    return (char)ft_toupper((int)c);
}

#include <stdio.h>

int main(void)
{
	const char *input = "Hello, world!";
	char x = 'a';
	char *result;

	// Apply the conversion function to the input string
	result = ft_strmapi(input, ft_toupper_wrapper);

	if (result)
	{
		// Print the original and transformed strings
		printf("Original: %s\n", input);
		printf("Transformed: %s\n", result);

		// Clean up allocated memory
		free(result);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}

	return (0);
}
*/