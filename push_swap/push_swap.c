/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:29:16 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/22 10:29:17 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*fre;

	fre = stack_a;
	while (stack_a)
	{
		tmp = stack_a;
		if (tmp->content < INT_MIN || tmp->content > INT_MAX)
		{
			ft_lstclear(&fre);
			(void)(write(2, "Error\n", 6) + ft_exit(4));
		}
		while (tmp->next)
		{
			if (tmp->next->content == stack_a->content)
			{
				ft_lstclear(&fre);
				(void)(write(2, "Error\n", 6) + ft_exit(4));
			}
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
}

void	check_av(int ac, char **av)
{
	t_index	id;

	id.i = -1;
	id.j = 0;
	if (ac == 2)
	{
		while (av[1][++id.i] != '\0')
			if (!(av[1][id.i] >= '0' && av[1][id.i] <= '9') && av[1][id.i] != 32
				&& av[1][id.i] != '-' && av[1][id.i] != '+')
				(void)(write(2, "Error\n", 6) + ft_exit(2));
		if (av[1][0] == '\0')
			(void)(write(2, "Error\n", 6) + ft_exit(2));
	}
	else
	{
		while (++id.j < ac)
		{
			id.i = -1;
			while (av[id.j][++id.i] != '\0')
				if (!(av[id.j][id.i] >= '0' && av[id.j][id.i] <= '9')
					&& av[id.j][id.i] != '-' && av[id.j][id.i] != '+')
					(void)(write(2, "Error\n", 6) + ft_exit(2));
		}
	}
}

t_list	*init_stack_a(char **av, int flag)
{
	t_list	*tmp;
	t_list	*stack_a;

	stack_a = NULL;
	tmp = NULL;
	while (av[flag])
	{
		tmp = ft_lstnew(av[flag]);
		ft_lstadd_back(&stack_a, tmp);
		flag++;
	}
	return (stack_a);
}

int	is_solved(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**matrix;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (ac < 2)
		(void)(write(2, "Error: few arguments\n", 22) + ft_exit(1));
	check_av(ac, av);
	if (ac == 2)
	{
		matrix = ft_split(av[1], ' ');
		stack_a = init_stack_a(matrix, 0);
		freemat(matrix);
	}
	else
		stack_a = init_stack_a(av, 1);
	check_double(stack_a);
	if (is_solved(stack_a))
		ft_lstclear(&stack_a);
	else
	{
		algorithm(&stack_a, &stack_b);
		ft_lstclear(&stack_b);
		ft_lstclear(&stack_a);
	}
}
