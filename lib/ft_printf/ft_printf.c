/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:31:07 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/06 13:21:13 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_ptr(unsigned long ptr, int *count)
{
	unsigned long	address;

	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	address = (unsigned long)ptr;
	ft_putstr("0x", count);
	ft_putnbr_unsigned(address, 16, "0123456789abcdef", count);
}

void	ft_conversion(char c, va_list args, int *count)
{
	char	*hex_digits;

	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
		ft_print_ptr(va_arg(args, unsigned long), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_signed(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), 10, "0123456789", count);
	else if (c == 'x')
	{
		hex_digits = "0123456789abcdef";
		ft_putnbr_unsigned(va_arg(args, unsigned int), 16, hex_digits, count);
	}
	else if (c == 'X')
	{
		hex_digits = "0123456789ABCDEF";
		ft_putnbr_unsigned(va_arg(args, unsigned int), 16, hex_digits, count);
	}
	else if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			ft_conversion(*format, args, &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
