/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:35:59 by espinell          #+#    #+#             */
/*   Updated: 2023/10/09 14:36:08 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int digit)
{
	if (digit < '0' || digit > '9')
	{
		return (0);
	}
	return (1);
}

/*int main()
{
	int a;
	
	a = 'a';
	ft_isdigit(a);
	printf("%d", ft_isdigit(a));
}*/
