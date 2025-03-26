/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:29:01 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/22 10:29:02 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_algo(t_list **stack_a, t_list **stack_b)
{
	t_index	index;

	index.size = ft_lstsize(*stack_a);
	index.i = is_max(*stack_a);
	index.j = is_min(*stack_a);
	if (index.size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a, 1);
		return ;
	}
	else if (index.size == 4)
		algo_four(stack_a, stack_b);
	else if (index.size == 5)
		algo_five(stack_a, stack_b);
	if (is_solved(*stack_a))
		return ;
	if ((*stack_a)->content == index.i)
		rotate_a(stack_a, 1);
	if ((*stack_a)->next->content == index.i)
		rev_rotate_a(stack_a, 1);
	if ((*stack_a)->next->content == index.j)
		swap_a(stack_a, 1);
	if ((*stack_a)->next && (*stack_a)->next->content < (*stack_a)->content)
		rotate_a(stack_a, 1);
}

void	algo_four(t_list **stack_a, t_list **stack_b)
{
	t_index	index;

	index.tmp = is_min(*stack_a);
	while (stack_a)
	{
		if ((*stack_a)->content == index.tmp)
		{
			push_atob(stack_a, stack_b);
			break ;
		}
		rotate_a(stack_a, 1);
	}
	simple_algo(stack_a, stack_b);
	push_btoa(stack_a, stack_b);
}

void	algo_five(t_list **stack_a, t_list **stack_b)
{
	t_index	index;

	index.tmp = is_min(*stack_a);
	index.j = is_max(*stack_a);
	index.i = 0;
	while (stack_a)
	{
		if ((*stack_a)->content == index.tmp || (*stack_a)->content == index.j)
			index.i++;
		if ((*stack_a)->content == index.tmp || (*stack_a)->content == index.j)
			push_atob(stack_a, stack_b);
		if ((*stack_a)->content == index.tmp || (*stack_a)->content == index.j)
			index.i++;
		if ((*stack_a)->content == index.tmp || (*stack_a)->content == index.j)
			push_atob(stack_a, stack_b);
		if (index.i == 2)
			break ;
		rotate_a(stack_a, 1);
	}
	simple_algo(stack_a, stack_b);
	push_btoa(stack_a, stack_b);
	push_btoa(stack_a, stack_b);
	if ((*stack_a)->content == index.tmp)
		swap_a(stack_a, 1);
	rotate_a(stack_a, 1);
}

void	algorithm(t_list **stack_a, t_list **stack_b)
{
	int			med;
	static int	*tab;
	t_index		index;

	tab = sort_array(*stack_a);
	while (ft_lstsize(*stack_a) > 5)
	{
		med = get_med(tab, *stack_a);
		index.size = ft_lstsize(*stack_a);
		while (stack_a)
		{
			set_index(*stack_a);
			index.tmp = get_cost_med(*stack_a, med);
			if (index.tmp == -1)
				break ;
			push(stack_a, stack_b, index.tmp, index.size);
		}
		free(tab);
		tab = sort_array(*stack_a);
	}
	free(tab);
	simple_algo(stack_a, stack_b);
	reverse_algo(stack_a, stack_b);
}

void	push(t_list **stack_a, t_list **stack_b, int i, int size)
{
	while (stack_a)
	{
		if (i < size / 2)
		{
			if ((*stack_a)->index == i)
			{
				push_atob(stack_a, stack_b);
				break ;
			}
			else
				rotate_a(stack_a, 1);
		}
		else
		{
			if ((*stack_a)->index == i)
			{
				push_atob(stack_a, stack_b);
				break ;
			}
			else
				rev_rotate_a(stack_a, 1);
		}
	}
}
