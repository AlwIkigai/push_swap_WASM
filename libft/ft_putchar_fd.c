/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:48:46 by asyed             #+#    #+#             */
/*   Updated: 2023/09/19 17:48:48 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Use the write system call to output the character to the file descriptor.
// The second argument is the address of the character.
// s: The string to output.
// fd: The file descriptor on which to write.
// Outputs the character ’c’ to the given file descriptor.

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	char	a;

	a = 'h';
	ft_putchar_fd(a, STDOUT_FILENO);
	return (0);
}
*/