/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:44:17 by espinell          #+#    #+#             */
/*   Updated: 2023/10/19 11:04:33 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_d;
	size_t	size_s;

	i = ft_strlen(dst);
	size_d = ft_strlen(dst);
	size_s = ft_strlen(src);
	j = 0;
	if (size <= 0)
		return (size_s + size);
	while (i < (size - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size < size_d)
		return (size_s + size);
	else
		return (size_d + size_s);
}

/*int main()
{
	char d[]="ciao";
	char s[]="123456";
	ft_strlcat(d, s, 0);
	printf("%s\n", d);
	printf("%zu", ft_strlcat(d, s, 0));
}*/
