/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:55:10 by espinell          #+#    #+#             */
/*   Updated: 2024/08/01 13:41:39 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*readline_heredoc(char *str, t_shell *shell, int fd)
{
	char	*line;

	line = readline(str);
	if (is_valid_line(line, 1))
		shell->flag = 0;
	if (!line)
	{
		printf("exit\n");
		close(fd);
		ft_quit(shell, shell->exit_status, 0);
	}
	ft_lstadd_front(garbage_collector(), ft_lstnew(line));
	return (line);
}
