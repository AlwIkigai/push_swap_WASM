/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:54:56 by asyed             #+#    #+#             */
/*   Updated: 2023/09/06 13:54:58 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && 'Z' >= c)
		return (c + 32);
	else
		return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	char UC;
	char LC;

	UC = 'H';
	LC = ft_islower(UC);

	printf("%c\n", UC);
	printf("%c\n", LC);
}
*/