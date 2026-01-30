/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:32:06 by asyed             #+#    #+#             */
/*   Updated: 2023/09/19 18:32:09 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: The string to output.
// fd: The file descriptor on which to write.
// Outputs the string ’s’ + newline.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		write(fd, s, len);
		write(fd, "\n", 1);
	}
}

/*
int	main(void)
{
	char	*str = "Hello, World!";

	ft_putendl_fd(str, STDOUT_FILENO);
	return (0);
}
*/