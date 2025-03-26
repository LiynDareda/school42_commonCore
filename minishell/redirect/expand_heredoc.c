/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:08:20 by espinell          #+#    #+#             */
/*   Updated: 2024/07/25 11:58:10 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*res_or_line(char *res, char *line)
{
	if (res)
		return (res);
	return (line);
}

static char	*copytmp(char *res, char *tmp)
{
	char	*tmp2;

	if (res)
	{
		tmp2 = ft_strjoin(res, tmp);
		res = tmp2;
	}
	else
		res = ft_strdup(tmp, 0);
	return (res);
}

char	*expand_varline(char *line, t_shell *shell)
{
	int		i;
	char	*res;
	char	*tmp;

	i = 0;
	res = NULL;
	while (line[i])
	{
		tmp = res;
		if (line[i] == '$')
		{
			if (line[i + 1] == '?')
			{
				tmp = ft_substitute(line, ft_itoa(shell->exit_status));
				res = copytmp(res, tmp);
			}
			else if (line[i + 1] != ' ' && line[i + 1] != '\0')
			{
				tmp = ft_substitute(line, ft_check_var(line, ++i, shell));
				res = copytmp(res, tmp);
			}
		}
		i++;
	}
	return (res_or_line(res, line));
}
