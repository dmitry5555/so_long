/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:35:38 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/06 16:31:57 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		len += ft_putchar(*str++);
	return (len);
}

int	ft_num(unsigned long long nbr, int base, char *str, int mod)
{
	int	nbr_list[100];
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (mod == 1 && (int)nbr < 0)
	{
		len += ft_putchar('-');
		nbr *= -1;
	}
	if (mod == 2)
		len += ft_putstr("0x");
	if (nbr == 0)
		len += ft_putchar('0');
	while (nbr)
	{
		nbr_list[i++] = nbr % base;
		nbr /= base;
	}
	while (i--)
		len += ft_putchar(str[nbr_list[i]]);
	return (len);
}

int	convert_var(va_list args, char curr_format)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (curr_format == '%')
		len += ft_putchar('%');
	if (curr_format == 'c')
		len += ft_putchar(va_arg(args, int));
	if (curr_format == 's')
		len += ft_putstr(va_arg(args, char *));
	if (curr_format == 'u')
		len += ft_num(va_arg(args, unsigned int), 10, "0123456789", 0);
	if (curr_format == 'd' || curr_format == 'i')
		len += ft_num(va_arg(args, int), 10, "0123456789", 1);
	if (curr_format == 'x')
		len += ft_num(va_arg(args, unsigned int), 16, "0123456789abcdef", 0);
	if (curr_format == 'X')
		len += ft_num(va_arg(args, unsigned int), 16, "0123456789ABCDEF", 0);
	if (curr_format == 'p')
		len += ft_num(va_arg(args, unsigned long long), 16, base, 2);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' )
		{
			str++;
			len += convert_var(args, *str);
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}
