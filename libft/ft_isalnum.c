/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:34:32 by asyed             #+#    #+#             */
/*   Updated: 2023/09/06 20:34:34 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*

#include <stdio.h>

int	main(void)
{
	char	alnum;

	alnum = '$';
	{
	if (ft_isalnum(alnum))
		printf("%c is alpha numeric\n", alnum);
	else
		printf("%c is NOT alpha numeric\n", alnum);
	}
	return(0);
}*/