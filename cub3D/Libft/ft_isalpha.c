/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:54:29 by espinell          #+#    #+#             */
/*   Updated: 2023/10/09 12:34:12 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int alpha)
{
	if (alpha < 'A' || (alpha > 'Z' && alpha < 'a') || alpha > 'z' )
	{
		return (0);
	}
	return (1);
}

/*int main()
{
	int a = '1';
	ft_isalpha(a);
	printf("%d",ft_isalpha(a));
}*/
