/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:08:04 by asyed             #+#    #+#             */
/*   Updated: 2023/09/19 17:08:08 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// total_len = copy the first string (s1) into the result.
// Make sure strlcpy returns the length of the string it tried to create.
// s1 = first string s2 = second string
// return = new string

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len1 + len2 + 1);
	ft_strlcpy(result + len1, s2, len2 + 1);
	return (result);
}

/*

#include <stdio.h>

int	main(void)
{
	const char *a = "Hello, ";
	const char *b = "Handsome ~!";

    // Call ft_strjoin to concatenate a and b, and store the result in 'result'.

    char *result = ft_strjoin(a, b);

    // Check if the result is not NULL (malloc might fail).
    if (result != NULL) {
        // Print the concatenated string.
        printf("Concatenated string: %s\n", result);

        // Free the dynamically allocated memory when done.
        free(result);
    } else {
        // Handle the case where memory allocation failed.
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/