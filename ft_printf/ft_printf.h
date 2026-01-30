/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:13:09 by asyed             #+#    #+#             */
/*   Updated: 2023/10/17 12:13:11 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h> 
# include <stdarg.h>

int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *s);
int		ft_strlen_pf(const char *s);
int		ft_putnbr_pf(int n, int base);
int		ft_putunbr_pf(unsigned int n, int base);
int		ft_puthex_pf(unsigned int n, char specifier);
int		ft_voidptr_pf(unsigned long p);
int		ft_printf(const char *format, ...);

#endif