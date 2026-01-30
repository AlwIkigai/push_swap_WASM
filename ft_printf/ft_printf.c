/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:24:17 by asyed             #+#    #+#             */
/*   Updated: 2023/10/27 18:04:19 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// variadic functons
// ap means argument pointer
// VA means variable or vector argument
// va start move argument to beginning or argument
// va_arg, fetch next argument

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar_pf(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr_pf(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_voidptr_pf(va_arg(ap, unsigned long));
	else if (specifier == 'd')
		count += ft_putnbr_pf((long)(va_arg(ap, int)), 10);
	else if (specifier == 'i')
		count += ft_putnbr_pf((long)(va_arg(ap, int)), 10);
	else if (specifier == 'u')
		count += ft_putunbr_pf((long)(va_arg(ap, unsigned int)), 10);
	else if (specifier == 'x' || specifier == 'X')
		count += ft_puthex_pf((long)(va_arg(ap, unsigned int)), specifier);
	else if (specifier == '%')
		count += ft_putchar_pf('%');
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start (ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format (*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end (ap);
	return (count);
}
/*
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int	main(void)
{
	int	c1;
	int c2;
	int str1;
	int	str2;
	int dec1;
	int	dec2;
	int integ1;
	int integ2;
	int	pos1;
	int	pos2;
	int	hex1;
	int	hex2;
	int	perc1;
	int	perc2;
	int	v1;
	int	v2;

//	c1 = ft_printf("%c", 'H');
//	printf(" count is: %d", c1);

//	c2 = printf("%c", 'H');
//	printf(" count is: %d", c2);

//	str1 = ft_printf("%s", "Hello");
//	printf(" count is: %d", str1);

//	str2 = printf("%s", "Hello");
//	printf(" count is: %d\n", str2);

//	dec1 = ft_printf("%d", -42);
//	printf(" count is %d", dec1);

//	dec2 = printf("%d", -42);
//	printf(" count is %d", dec2);

//	integ1 = ft_printf("%i", -42);
//	printf(" count is %d", integ1);

//	integ2 = printf("%i", -42);
//	printf(" count is %d", integ2);

//	pos1 = ft_printf("%i", 42);
//	printf(" count is %d", pos1);

//	pos1 = ft_printf("%i", 42);
//	printf(" count is %d", pos1);

//	hex1 = ft_printf("%x", 13);
//	printf(" count is %d", hex1);

//	hex1 = printf("%x", 13);
//	printf(" count is %d", hex1);

//	hex1 = ft_printf("%x", 15);
//	printf(" count is %d", hex1);

//	hex1 = printf("%x", 15);
//	printf(" count is %d", hex1);

//	hex1 = ft_printf("%x", 26);
//	printf(" count is %d", hex1);

//	hex1 = ft_printf("%x", 255);
//	printf(" count is %d", hex1);

//	hex2 = ft_printf("%X", 13);
//	printf(" count is %d", hex2);

//	hex2 = printf("%X", 13);
//	printf(" count is %d", hex2);

//	hex2 = ft_printf("%X", 15);
//	printf(" count is %d", hex2);

//	hex2 = printf("%X", 15);
//	printf(" count is %d", hex2);

//	hex2 = ft_printf("%X", 26);
//	printf(" count is %d", hex2);

//	hex2 = ft_printf("%X", 255);
//	printf(" count is %d", hex2);

//	perc1 = ft_printf("%%");
//	printf(" count is %d", perc1);

//	perc1 = printf("%%");
//	printf(" count is %d", perc1);

//	perc1 = ft_printf("%%%%%%");
//	printf(" count is %d", perc1);

//	perc1 = printf("%%%%%%");
//	printf(" count is %d", perc1);

//	v1 = 42;
//	printf("%p\n", (void *)&v1);
//	ft_printf("%p", (void *)&v1);
	
}
*/
