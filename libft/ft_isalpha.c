/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:45:38 by asyed             #+#    #+#             */
/*   Updated: 2023/12/16 17:13:57 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	alpha;

	alpha = 'a';
	{
		if (ft_isalpha(alpha))
			printf("%c is an alphabet\n", alpha);
		else
			printf("%c is NOT an alphabet\n", alpha);
	}
	return(0);
}
*/