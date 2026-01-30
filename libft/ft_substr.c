/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:05:19 by asyed             #+#    #+#             */
/*   Updated: 2023/09/20 17:05:21 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s = string from which to create sub str
// start: start index of the substr in the str 's'
// len; max len of substr
// return -> substr (start to len)

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

/*
#include <stdio.h>

int main(void)
{
    const char *input = "Hello, World!";
    unsigned int start = 7;
    size_t length = 5;

    char *substring = ft_substr(input, start, length);

    if (substring)
    {
        printf("Original String: %s\n", input);
        printf("Substring (start=%u, len=%zu): %s\n", start, len, substr);

        // Clean up allocated memory
        free(substring);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return (0);
}
*/