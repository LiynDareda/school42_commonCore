/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:22:12 by espinell          #+#    #+#             */
/*   Updated: 2023/10/19 14:15:06 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	j;
	size_t	size_l;

	x = 0;
	j = 0;
	size_l = ft_strlen(little);
	if (size_l == 0)
		return ((char *)big);
	while (big[x] != '\0' && x < len)
	{
		if (big[x] == little[0])
		{
			j = 0;
			while (big[x + j] == little[j] && big[x + j] && (x + j) < len)
				j++;
			if (j == size_l)
				return ((char *)(big + x));
		}
		x++;
	}
	return (0);
}

/*int main()
{
	char a[]= "emamerdacane";
	char b[]= "mami";
	printf("%s", ft_strnstr(a, b, 4));
}*/
