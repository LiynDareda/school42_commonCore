/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:47:21 by espinell          #+#    #+#             */
/*   Updated: 2023/10/10 10:36:38 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

/*int main()
{
	char str[] = "12345678";
	char dest[8];
	ft_memcpy(dest, str, 5);
	printf("%s", dest);
}*/
