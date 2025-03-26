/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:34:08 by lbarlett          #+#    #+#             */
/*   Updated: 2023/11/10 16:44:09 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int	count;
	unsigned long tmp;

	count = 0;
	if (!ptr)
		return (ft_print_str("(nil)"));
	tmp = (unsigned long) ptr;
	count += write(1, "0x", 2);
	count += ft_print_ptr_base(tmp, 16);
	return (count);
}

int	ft_print_ptr_base(unsigned long nb, unsigned long base)
{
	int		count;
	char	*str;

	str = "0123456789abcdef";
	if (nb < base)
		return (ft_print_chr(str[nb]));
	else
	{
		count = ft_print_ptr_base(nb / base, base);
		return (count + ft_print_ptr_base(nb % base, base));
	}
}
