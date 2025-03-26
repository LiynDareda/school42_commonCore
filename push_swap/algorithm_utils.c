/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:28:50 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/22 10:28:51 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list *stack)
{
	t_index	index;
	t_list	*tmp;

	index.i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->index = index.i;
		index.i++;
		tmp = tmp->next;
	}
}

void	reverse_algo(t_list **stack_a, t_list **stack_b)
{
	t_index	index;

	while (*stack_b)
	{
		set_index(*stack_b);
		index.i = is_max_index(*stack_b);
		index.j = is_pre(*stack_b, get_content(*stack_b, index.i));
		if (ft_lstsize(*stack_b) == 3)
		{
			final_sort(stack_a, stack_b);
			break ;
		}
		if (index.j == -1)
		{
			push_btoa(stack_a, stack_b);
			break ;
		}
		if (index.i == LONG_MIN || index.j == LONG_MIN)
			break ;
		who_push_next(stack_a, stack_b, index.i, index.j);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a, 1);
}

void	who_push_next(t_list **stack_a, t_list **stack_b, int i, int j)
{
	t_index	index;

	set_index(*stack_b);
	index.i = get_cost(*stack_b, i);
	index.j = get_cost(*stack_b, j);
	if (index.i < index.j)
		push_next(stack_a, stack_b, i);
	else
	{
		push_next(stack_a, stack_b, j);
		push_next(stack_a, stack_b, i);
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a, 1);
	}
}

void	push_next(t_list **stack_a, t_list **stack_b, int i)
{
	t_index	index;

	index.size = ft_lstsize(*stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->index == i)
		{
			push_btoa(stack_a, stack_b);
			break ;
		}
		else if (i <= index.size / 2)
			rotate_b(stack_b, 1);
		else if (i > index.size / 2)
			rev_rotate_b(stack_b, 1);
	}
}
