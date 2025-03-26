/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:30:14 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/22 10:30:15 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	t_index	n;

	n.i = 0;
	n.j = 0;
	n.tmp = 0;
	if (s[n.i] == '+' || s[n.i] == '-')
	{
		if (s[n.i] == '-')
			n.j++;
		n.i++;
	}
	if (s[n.i] == '\0')
		(void)(write(2, "Error\n", 6) + ft_exit(3));
	while (s[n.i] >= '0' && s[n.i] <= '9')
	{
		n.tmp = (n.tmp * 10 + s[n.i] - 48);
		n.i++;
	}
	if (s[n.i] != '\0')
		(void)(write(2, "Error\n", 6) + ft_exit(3));
	if (n.j == 1)
		n.tmp = -n.tmp;
	return (n.tmp);
}

void	freemat(char **matrix)
{
	int	l;

	l = 0;
	while (matrix[l])
	{
		free (matrix[l]);
		l++;
	}
	free (matrix);
}

int	ft_exit(int id)
{
	exit (id);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	fill_tab(t_list *stack_a, int *tab)
{
	int		i;
	t_list	*tmp;

	tmp = stack_a;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
}
