/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:13:25 by asyed             #+#    #+#             */
/*   Updated: 2023/09/19 18:13:26 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: The string to output.
// fd: The file descriptor on which to write.
// Outputs the string ’s’ to the given file descriptor.

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}
/*
int	main(void)
{
	char	*str = "Hello, World!";

	ft_putstr_fd(str, STDOUT_FILENO);
	return (0);
}
*/