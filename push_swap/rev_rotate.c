/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:29:47 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/22 10:29:48 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **stack_a, int f)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	if (ft_lstsize(*stack_a) == 2)
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->next = tmp;
		tmp->next = NULL;
	}
	else
	{
		while ((*stack_a)->next->next)
		{
			last = (*stack_a)->next;
			*stack_a = (*stack_a)->next;
		}
		*stack_a = ft_lstlast(*stack_a);
		(*stack_a)->next = tmp;
		last->next = NULL;
		if (f == 1)
			write(1, "rra\n", 4);
	}
}

void	rev_rotate_b(t_list **stack_b, int f)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	if (ft_lstsize(*stack_b) == 2)
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->next = tmp;
		tmp->next = NULL;
	}
	else
	{
		while ((*stack_b)->next->next)
		{
			last = (*stack_b)->next;
			*stack_b = (*stack_b)->next;
		}
		*stack_b = ft_lstlast(*stack_b);
		(*stack_b)->next = tmp;
		last->next = NULL;
		if (f == 1)
			write(1, "rrb\n", 4);
	}
}

void	rev_rotate_r(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_a(stack_a, 0);
	rev_rotate_b(stack_b, 0);
	write(1, "rrr\n", 4);
}
