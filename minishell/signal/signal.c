/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:43:50 by espinell          #+#    #+#             */
/*   Updated: 2024/08/06 11:43:51 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ctrl_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_sigflag = SIGINT;
		*exit_status() = 130;
		garbage_collector_free(1);
		exit (130);
	}
}

void	ctrl_executor(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_sigflag = SIGINT;
	}
}
