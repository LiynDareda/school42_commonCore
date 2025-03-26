/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:30:23 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/22 10:30:24 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a, int f)
{
	t_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (f == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b, int f)
{
	t_list	*tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->next->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (f == 1)
		write(1, "sb\n", 3);
}

void	swap_s(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(1, "ss\n", 3);
}
