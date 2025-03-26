/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:25:37 by espinell          #+#    #+#             */
/*   Updated: 2023/10/11 19:25:51 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *nptr)
{
	int	x;
	int	s;
	int	num;

	num = 0;
	x = 0;
	s = 1;
	while (nptr[x] == ' ' || (nptr[x] >= 9 && nptr[x] <= 13))
		x++;
	if (nptr[x] == '-' || nptr[x] == '+')
	{
		if (nptr[x] == '-')
			s *= -1;
		x++;
	}
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		num *= 10;
		num += nptr[x] -48;
		x++;
	}
	return (num * s);
}

/*int main()
{
	char a[]="\t\n123045678";
	int tmp;
	tmp=ft_atoi(a);
	printf("%d\n", tmp);
	tmp=atoi(a);
	printf("%d\n", tmp);
}*/
