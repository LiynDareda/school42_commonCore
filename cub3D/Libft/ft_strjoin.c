/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:05:22 by espinell          #+#    #+#             */
/*   Updated: 2023/10/19 16:15:56 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	size_t	j;
	size_t	z;
	size_t	i;
	char	*fstr;

	x = ft_strlen(s1);
	j = ft_strlen(s2);
	z = -1;
	fstr = (char *)malloc(sizeof (char) * (x + j + 1));
	if (!fstr)
		return (NULL);
	while (s1[++z])
		fstr[z] = s1[z];
	i = z;
	z = -1;
	while (s2[++z])
		fstr[i + z] = s2[z];
	fstr[i + z] = '\0';
	return (fstr);
}
/*
	fstr[0] = '\0';
	ft_strlcat(fstr, s1, x + 1);
	ft_strlcat(fstr, s2, z);
	fstr[z] = '\0';
	return (fstr);
int main() {
    const char *str1 = "\0";
    const char *str2 = "world!";
    char *result = ft_strjoin(str1, str2);

    if (result) {
        printf("Joined string: '%s'\n", result);
        free(result); // Libera il puntatore dopo l'uso
    } else {
        printf("Errore nell'allocazione di memoria.\n");
    }

    return 0;
}*/
/*int main()
{
	char a[]="ciao1234 ";
	char b[]="mondo";
	char *c;

	c = ft_strjoin(a, b);
	printf("%s",c);
	free (c);
}*/
