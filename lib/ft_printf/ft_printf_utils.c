/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:29:35 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/06 13:20:53 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_putchar(*str++, count);
}

void	ft_putnbr_signed(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_signed(n / 10, count);
	ft_putchar((n % 10) + '0', count);
}

void	ft_putnbr_unsigned(unsigned int n, int base, char *digits, int *count)
{
	if (n >= (unsigned int)base)
		ft_putnbr_unsigned(n / base, base, digits, count);
	ft_putchar(digits[n % base], count);
}
