/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:30:09 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/22 10:30:10 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_list **stack_a, t_list**stack_b)
{
	while (*stack_b)
	{
		if ((*stack_b)->content == is_max(*stack_b))
			push_btoa(stack_a, stack_b);
		else
			rotate_b(stack_b, 1);
	}
}

int	get_content(t_list *stack, int i)
{
	while (stack)
	{
		if (stack->index == i)
			return (stack->content);
		stack = stack->next;
	}
	return (INT_MIN);
}

int	get_cost(t_list *stack, int i)
{
	t_index	index;

	if (i <= ft_lstsize(stack) / 2)
		index.i = i;
	else
		index.i = ft_lstsize(stack) - i + 1;
	return (index.i);
}

int	get_cost_med(t_list *stack_a, int med)
{
	t_index	index;

	index.size = ft_lstsize(stack_a);
	index.j = INT_MAX;
	index.i = -1;
	while (stack_a)
	{
		if (stack_a->content < med)
		{
			if (stack_a->index < index.size / 2 && stack_a->index < index.j)
			{
				index.j = stack_a->index;
				index.i = stack_a->index;
			}
			else if (stack_a->index >= index.size / 2
				&& index.size - stack_a->index < index.j)
			{
				index.j = index.size - stack_a->index;
				index.i = stack_a->index;
			}
		}
		stack_a = stack_a->next;
	}
	return (index.i);
}

int	*sort_array(t_list *stack_a)
{
	int		*tab;
	t_index	index;

	index.size = ft_lstsize(stack_a);
	tab = (int *)malloc(sizeof(int) * index.size);
	if (!tab)
		return (0);
	fill_tab(stack_a, tab);
	index.i = -1;
	while (++index.i < index.size - 1)
	{
		index.j = -1;
		while (++index.j < index.size - index.i - 1)
		{
			if (tab[index.j] > tab[index.j + 1])
			{
				index.tmp = tab[index.j];
				tab[index.j] = tab[index.j + 1];
				tab[index.j + 1] = index.tmp;
			}
		}
	}
	return (tab);
}
