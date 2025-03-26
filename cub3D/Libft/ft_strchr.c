/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:26:44 by espinell          #+#    #+#             */
/*   Updated: 2023/10/19 11:30:42 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*t;
	unsigned char	i;

	i = 0;
	t = (char *) s;
	while (t[i] != '\0')
	{
		if ((unsigned char)c == t[i])
		{
			return (t + i);
		}
		i++;
	}
	if (t[i] == (unsigned char) c)
		return (t + i);
	return (0);
}
