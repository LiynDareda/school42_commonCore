/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:38:56 by espinell          #+#    #+#             */
/*   Updated: 2023/10/19 11:51:14 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t;

	t = (char *) s;
	i = ft_strlen(t);
	while ((unsigned char) i > 0)
	{
		if ((unsigned char)c == t[i])
		{
			return (t + i);
		}
		i--;
	}
	if (t[i] == (unsigned char) c)
		return (t + i);
	return (0);
}

/*int main()
{
	const char *s = "12345678";
	const char *t =ft_strrchr(s, '4');
	printf("%s", t);
}*/
