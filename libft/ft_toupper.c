/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:28:07 by asyed             #+#    #+#             */
/*   Updated: 2023/09/06 16:28:09 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && 'z' >= c)
		return (c - 32);
	else
		return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	char	LC;
	char	UC;

	LC = 'a';
	UC = ft_toupper(LC);
	printf("%c\n", LC);
	printf("%c\n", UC);
}
*/