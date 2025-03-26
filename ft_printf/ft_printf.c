/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:34:06 by lbarlett          #+#    #+#             */
/*   Updated: 2023/11/10 16:44:44 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_print_chr(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_print_str("(null)"));
	while (*str)
	{
		ft_print_chr((int)*str);
		count++;
		str++;
	}
	return (count);
}

int	ft_print_numb_base(long long nb, int base, char hex_format)
{
	int		count;
	char	*lstr;
	char	*ustr;

	lstr = "0123456789abcdef";
	ustr = "0123456789ABCDEF";
	if (nb < 0)
	{
		write(1, "-", 1);
		return (ft_print_numb_base(-nb, base, hex_format) + 1);
	}
	else if (nb < base && hex_format == 'l')
		return (ft_print_chr(lstr[nb]));
	else if (nb < base && hex_format == 'u')
		return (ft_print_chr(ustr[nb]));
	else
	{
		count = ft_print_numb_base(nb / base, base, hex_format);
		return (count + ft_print_numb_base(nb % base, base, hex_format));
	}
}

int	ft_print_body(char spec, va_list ap)
{
	int		count;

	count = 0;
	if (spec == 'c')
		count += ft_print_chr(va_arg(ap, int));
	else if (spec == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (spec == 'p')
		count += ft_print_ptr(va_arg(ap, void *));
	else if (spec == 'd' || spec == 'i')
		count += ft_print_numb_base((long long)va_arg(ap, int), 10, 'l');
	else if (spec == 'u')
		count += ft_print_numb_base((long long)va_arg(ap, unsigned int), 10, 'l');
	else if (spec == 'x')
		count += ft_print_numb_base((long long)va_arg(ap, unsigned int), 16, 'l');
	else if (spec == 'X')
		count += ft_print_numb_base((long long)va_arg(ap, unsigned int), 16, 'u');
	else if (spec == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *body, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, body);
	count = 0;
	while (*body)
	{
		if (*body == '%')
			count += ft_print_body(*(++body), ap);
		else
			count += write(1, body, 1);
		body++;
	}
	va_end(ap);
	return (count);
}
/*
int main()
{
	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
}*/