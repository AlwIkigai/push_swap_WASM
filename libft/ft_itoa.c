/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:35:20 by asyed             #+#    #+#             */
/*   Updated: 2023/09/20 12:35:22 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is neg handle both pos and neg int
// calculate len of str by /10 until less than 10
// allocates memory for str. including space for neg sign + null
// convert each digit on int to char and store in str in reverse order
// adds neg sign to str if int is negative
// null terminate str before returning it

#include "libft.h"

static size_t	checklen(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbl;
	int		i;
	char	*str;

	nbl = n;
	i = checklen(nbl) -1;
	str = (char *)ft_calloc((checklen(n) + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nbl < 0)
	{
		str[0] = '-';
		nbl *= -1;
	}
	while (nbl >= 0 && i >= 0)
	{
		str[i] = '0' + (nbl % 10);
		nbl /= 10;
		i--;
		if (nbl == 0)
			nbl = -1;
	}
	str[checklen(n)] = '\0';
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	int num = 12345;

	char *res = ft_itoa(num);

	if (res)
    {
        printf("Original Number: %d\n", num);
        printf("Resulting String: %s\n", res);

        // Clean up allocated memory
        free(res);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return (0);
}
*/