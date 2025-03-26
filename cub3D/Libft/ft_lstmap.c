/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:08 by espinell          #+#    #+#             */
/*   Updated: 2023/10/23 15:36:35 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*newnode;
	t_list	*tmp;
	void	*result;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	tmp = lst;
	newnode = NULL;
	list = NULL;
	while (tmp != NULL)
	{
		result = f(tmp->content);
		newnode = ft_lstnew(result);
		if (newnode == NULL)
		{
			del(result);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, newnode);
		tmp = tmp->next;
	}
	return (list);
}
