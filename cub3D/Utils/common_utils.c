/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:29:48 by lbarlett          #+#    #+#             */
/*   Updated: 2024/09/25 12:30:11 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*my_strdup(const char *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[j])
	{
		if (s[j] == '\t')
			i += 4;
		else
			i++;
		j++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[j])
	{
		if (s[j] == '\t')
		{
			i = 0;
			while (i < 4)
			{
				str[k++] = ' ';
				i++;
			}
		}
		else
		{
			str[k++] = s[j];
		}
		j++;
	}
	str[k] = '\0';
	return (str);
}