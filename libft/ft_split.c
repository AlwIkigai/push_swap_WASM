/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:17:26 by asyed             #+#    #+#             */
/*   Updated: 2023/09/21 15:17:28 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: str to be split
// c: delimiter char (, space)
// return: array of new str resulting from the split
// NULL if the allocation fails

// steps
// Count characters until the next delimiter 'c' or null terminator
// Count words delimited by 'c'
// Free the memory allocated for the array of strings
// Split the input string 's' into substrings based on the delimiter 'c'
#include "libft.h"

static int	count_char(char const *s, char c)
{
	int				char_count;

	char_count = 0;
	while (*s != '\0' && *s != c)
	{
		char_count++;
		s++;
	}
	return (char_count);
}

static int	count_words(char const *s, char c)

{
	int			word_count;

	word_count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			s += (count_char(s, c));
			word_count++;
		}
		else
			s++;
	}
	return (word_count);
}

static void	*free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free (strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t			word_index;
	size_t			i;
	char			**fullstringmemoryspace;

	i = 0;
	word_index = count_words(s, c);
	fullstringmemoryspace = (char **)malloc((word_index + 1) * sizeof(char *));
	if (fullstringmemoryspace == NULL || s == NULL)
		return (NULL);
	fullstringmemoryspace[word_index] = NULL;
	while (*s != '\0')
	{
		if (*s != c)
		{
			fullstringmemoryspace[i] = ft_substr(s, 0, count_char(s, c));
			if (fullstringmemoryspace[i] == NULL)
				return (free_split(fullstringmemoryspace));
			i++;
			s += count_char(s, c);
		}
		else
			s++;
	}
	return (fullstringmemoryspace);
}
/*
#include <stdio.h>

int main(void)
{
    const char *input = "This is a sample string";
    char delimiter = ' ';

    char **result = ft_split(input, delimiter);

    if (result)
    {
        printf("Original String: %s\n", input);
        printf("Split String: \n");

        int i = 0;
        while (result[i] != NULL)
        {
            printf("[%d]: %s\n", i, result[i]);
            i++;
        }

        // Free the memory allocated for the result
        int j = 0;
        while (result[j] != NULL)
        {
            free(result[j]);
            j++;
        }
        free(result);
    }
    else
    {
        printf("Memory allocation failed or no words found.\n");
    }

    return (0);
}
*/