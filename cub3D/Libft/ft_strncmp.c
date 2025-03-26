/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:17:14 by espinell          #+#    #+#             */
/*   Updated: 2023/10/19 12:17:41 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 && *s2 && n -1 > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 -(unsigned char)*s2);
}

/*int main()
{
	char s1[]= "ciAo";
	char s2[]= "ciao";
	printf("%d", ft_strncmp(s1, s2, 3));
}*/
