/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:29:59 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/22 10:30:00 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a, int f)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = ft_lstlast(*stack_a);
	last->next = tmp;
	tmp->next = NULL;
	if (f == 1)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b, int f)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = ft_lstlast(*stack_b);
	last->next = tmp;
	tmp->next = NULL;
	if (f == 1)
		write(1, "rb\n", 3);
}

void	rotate_r(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	write(1, "rr\n", 3);
}
