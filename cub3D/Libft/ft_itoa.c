/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:40:46 by espinell          #+#    #+#             */
/*   Updated: 2023/10/21 12:00:27 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numcount(int n)
{
	int			i;
	long long	num;

	i = 0;
	num = (long long) n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			x;
	int			j;
	int			size;
	char		*n_slot;
	long long	num;

	x = 0;
	num = (long long) n;
	size = ft_numcount(n);
	j = size - 1;
	n_slot = (char *)malloc(sizeof(char) * size + 1);
	if (!n_slot)
		return (NULL);
	if (num < 0)
	{
		n_slot[x++] = '-';
		num *= -1;
	}
	while (x++ < size)
	{
		n_slot[j--] = num % 10 + 48;
		num /= 10;
	}
	n_slot[x - 1] = '\0';
	return (n_slot);
}
/*int main()
{
	int num = -2147483648;
	printf("%s", ft_itoa(num));
}*/
