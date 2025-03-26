/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:59:09 by espinell          #+#    #+#             */
/*   Updated: 2023/10/18 16:40:19 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	s = (const char *)src;
	d = (char *)dest;
	if (!dest && !src)
		return (dest);
	if (s < d)
	{
		i = n + 1;
		while (--i > 0)
			d[i - 1] = s[i - 1];
	}
	else
	{
		i = -1;
		while (++i < n)
			d[i] = s[i];
	}
	return (dest);
}

/*int main()
{
	char a[]="12345678";
	char b[8];
	ft_memmove(b, a, 4);
	printf("%s", b);
}*/
