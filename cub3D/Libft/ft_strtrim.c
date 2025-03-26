/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:06:27 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 14:34:08 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cicloset(const char c, const char *s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		if (c == s[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	x;
	size_t	t;
	size_t	j;
	char	*tstr;

	x = 0;
	j = 0;
	while (s1[x] && cicloset(s1[x], set))
		x++;
	t = ft_strlen(s1) - 1;
	while (t > x && cicloset(s1[t], set))
		t--;
	tstr = (char *)malloc(sizeof(char) * (t - x) + 2);
	if (!tstr)
		return (NULL);
	while (x < (t + 1))
	{
		tstr[j] = s1[x];
		x++;
		j++;
	}
	tstr[j] = '\0';
	return (tstr);
}

/*int main()
{
	char str[]="z  ciao  x";
	char trim[]= " zx";
	printf("%s",ft_strtrim(str, trim));
}*/
