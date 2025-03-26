/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:12:26 by espinell          #+#    #+#             */
/*   Updated: 2023/10/23 14:08:20 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freemem(char **str, int x)
{
	while (x >= 0)
	{
		free(str[x]);
		x--;
	}
	free(str);
}

static int	ft_count_word(char *str, int c)
{
	int	x;
	int	word;

	x = 0;
	word = 0;
	while (str[x])
	{
		while (str[x] == c && str[x])
		{
			x++;
		}
		if (str[x] != c && str[x])
		{
			word++;
			while (str[x] != c && str[x])
			{
				x++;
			}
		}
	}
	return (word);
}

static void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	x;

	x = 0;
	while (str[j] == c && str[j])
		j++;
	while (str[j + x] != c && str[j + x])
	{
		word[x] = str[j + x];
		x++;
	}
	word[x] = '\0';
}

static char	*ft_allocstr(char *str, char c, int *j)
{
	char	*word;
	int		x;
	int		i;

	i = 0;
	x = *j;
	word = NULL;
	while (str[*j])
	{
		if (str[*j] != c)
		{
			while (str[*j] != c && str[*j])
			{
				*j += 1;
				i++;
			}
			word = (char *)malloc(sizeof(char) * (i + 1));
			if (!word)
				return (NULL);
			break ;
		}
		*j += 1;
	}
	ft_strcpy(word, str, c, x);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**f_str;
	int		x;
	int		j;
	int		word;

	x = 0;
	j = 0;
	if (!s)
		return (NULL);
	word = ft_count_word((char *)s, c);
	f_str = (char **)malloc(sizeof(char *) * (word + 1));
	if (!f_str)
		return (NULL);
	while (x < word)
	{
		f_str[x] = ft_allocstr((char *) s, c, &j);
		if (!f_str[x])
		{
			ft_freemem (f_str, x);
			return (NULL);
		}
		x++;
	}
	f_str[word] = NULL;
	return (f_str);
}

/*int main() {
    char *input = "----ciao----come----va---?--";
    char **result;
    char delimiter = '-'; // You can change the delimiter as needed

    result = ft_split(input, delimiter);

    if (result == NULL) {
        printf("Split failed, returned NULL\n");
        return 1;
    }

    int i = 0;
    while (result[i] != NULL) {
        printf("Word %d: %s\n", i + 1, result[i]);
        free(result[i]);
        i++;
    }

    free(result);

    return 0;
}*/
