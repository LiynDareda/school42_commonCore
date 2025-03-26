/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:04:16 by espinell          #+#    #+#             */
/*   Updated: 2023/10/23 15:35:28 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next_n;

	current = *lst;
	next_n = *lst;
	if (!lst || !*lst || !del)
		return ;
	while (current)
	{
		next_n = next_n->next;
		del(current->content);
		free(current);
		current = next_n;
	}
	*lst = NULL;
}
