/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:52:34 by asyed             #+#    #+#             */
/*   Updated: 2024/04/26 09:45:43 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}

/*
#include <stdio.h>

int main(void)
{
    // Test cases
    const char *test_strings[] = {
        "12345",         // Positive number
        "-9876",         // Negative number
        "   42",         // Leading whitespace
        "123abc",        // Non-digit characters
        "  +123",        // Leading '+' sign
        "  -456",        // Leading '-' sign
        "   0",          // Zero
        "  -0  "         // Zero with whitespace
    };

    printf("Results of ft_atoi:\n");

    int i = 0;
    while (i < sizeof(test_strings) / sizeof(test_strings[0]))
    {
        const char *str = test_strings[i];
        int result = ft_atoi(str); // Use the custom ft_atoi function
        printf("\"%s\" -> %d\n", str, result);
        i++;
    }

    return (0);
}
*/