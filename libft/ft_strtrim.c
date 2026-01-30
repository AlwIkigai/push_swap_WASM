/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:32:28 by asyed             #+#    #+#             */
/*   Updated: 2023/09/20 17:32:29 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s1 = str to be trimmed
// set = reference set of char to trim
// return value = trimmed str, NULL if allocation fail

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	trimmed = (char *)malloc((len + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len + 1);
	return (trimmed);
}

/*
#include <stdio.h>

int	main(void)
{
	// Test case 1: Trimming leading and trailing whitespaces
	char *s1 = "   Hello, World!   ";
	char *set1 = " ";
	char *result1 = ft_strtrim(s1, set1);
	printf("Test case 1: \"%s\" -> \"%s\"\n", s1, result1);
	free(result1);

	// Test case 2: Trimming leading and trailing specified characters
	char *s2 = "___Hello, World!___";
	char *set2 = "_";
	char *result2 = ft_strtrim(s2, set2);
	printf("Test case 2: \"%s\" -> \"%s\"\n", s2, result2);
	free(result2);

	// Test case 3: No trimming required
	char *s3 = "NoTrimmingNeeded";
	char *set3 = " ";
	char *result3 = ft_strtrim(s3, set3);
	printf("Test case 3: \"%s\" -> \"%s\"\n", s3, result3);
	free(result3);

	// Test case 4: Empty input string
	char *s4 = "";
	char *set4 = " ";
	char *result4 = ft_strtrim(s4, set4);
	printf("Test case 4: \"%s\" -> \"%s\"\n", s4, result4);
	free(result4);

	return (0);
}
*/