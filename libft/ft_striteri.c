/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:23:30 by asyed             #+#    #+#             */
/*   Updated: 2023/09/20 21:23:32 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s = str to iterate
// f = function to apply to each char
// return = none // function exit immediately

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include "libft.h"
#include <stdio.h>

// Function wrapper that calls ft_tolower on each character
void to_lower(unsigned int index, char *c)
{
    *c = ft_tolower(*c);
}

int main(void)
{
    char str[] = "Hello, WoRLD!";

    printf("Original string: %s\n", str);

    // Apply ft_tolower to each character in the string
    ft_striteri(str, to_lower);

    printf("Converted to lowercase: %s\n", str);

    return (0);
}
*/