/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:25:48 by espinell          #+#    #+#             */
/*   Updated: 2023/10/19 14:37:56 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		x;
	char	*str;

	x = 0;
	str = (char *)malloc(sizeof (char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[x])
	{
		str[x] = s[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

/*int main()
{
	char *f;
	char s[]= "ciao";
	f = ft_strdup(s);
	printf("%s",f);
	free (f);
}*/
