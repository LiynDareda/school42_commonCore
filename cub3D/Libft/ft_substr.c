/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:02:22 by espinell          #+#    #+#             */
/*   Updated: 2023/10/19 15:16:34 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size_s;
	size_t	x;
	char	*str;

	x = 0;
	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	if (start > size_s)
		start = size_s;
	if (len > (size_s - start))
		len = (size_s - start);
	if (start == size_s)
		str = (char *)malloc(sizeof(char));
	else
		str = (char *)malloc((sizeof(char) * len) + 1);
	if (!str)
		return (NULL);
	while (x < len && s[start] && start < size_s)
		str[x++] = s[start++];
	str[x] = '\0';
	return (str);
}

/*int main()
{
	char a[]="ciao mondo";
	char *f;
	f = ft_substr(a, 3, -3);
	printf("%s", f);
	free (f);
}*/
