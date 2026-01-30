/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:02:52 by asyed             #+#    #+#             */
/*   Updated: 2023/09/11 17:04:09 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// link back to lib for strlen
// cc with libft.a
// Duplicate str via malloc (heap)
// Dynamic memory allocation

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>

int main(void)
{
    const char *original = "Hello, world!";
    char *duplicate = ft_strdup(original);

    if (duplicate)
    {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);

        free(duplicate); // Don't forget to free the allocated memory.
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return (0);
}*/