/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:59:36 by espinell          #+#    #+#             */
/*   Updated: 2023/10/19 13:48:54 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			x;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	x = 0;
	if (n <= 0)
		return (0);
	while (x < n && str1[x] == str2[x])
		x++;
	if (x == n)
		return (str1[x - 1] - str2[x - 1]);
	else
		return (str1[x] - str2[x]);
}

/*int main()
{
	unsigned char a[]= ".........";
	unsigned char b[]= ".........";
	printf("%c", ft_memcmp(a, b, 10));
}*/
