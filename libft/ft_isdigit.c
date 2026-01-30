/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:33:52 by asyed             #+#    #+#             */
/*   Updated: 2023/09/06 17:33:53 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
/*

#include <stdio.h>

int	main(void)
{
	char	digit;

	digit = 'a';
	{
		if (ft_isdigit(digit))
			printf("%c is a digit\n", digit);
		else
			printf("%c is not a digit\n", digit);
	}
	return(0);
}
*/
