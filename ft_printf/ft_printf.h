/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:34:02 by lbarlett          #+#    #+#             */
/*   Updated: 2023/11/10 16:44:15 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_print_chr(int c);
int	ft_print_ptr(void *ptr);
int	ft_print_str(char *str);
int	ft_print_numb_base(long long nb, int base, char hex_format);
int	ft_print_ptr_base(unsigned long nb, unsigned long base);
int	ft_print_body(char spec, va_list ap);
int	ft_printf(const char *body, ...);

#endif