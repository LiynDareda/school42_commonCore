/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:46:56 by espinell          #+#    #+#             */
/*   Updated: 2023/11/20 12:17:34 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static char	*read_line(int fd, char *buf, char *backup)
{
	char	*tmp;
	int		check;

	check = 1;
	while (check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (NULL);
		if (check == 0)
			break ;
		buf[check] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *backup)
{
	char	*line;
	int		start;
	int		i;

	i = -1;
	start = 0;
	if (!backup || backup[0] == '\0')
		return (NULL);
	while (backup[start] != '\n' && backup[start] != '\0')
		start++;
	line = (char *)malloc(sizeof(char) * start + 1 + (backup[start] == '\n'));
	if (!line)
		return (NULL);
	while (backup[++i] != '\n' && backup[i] != '\0')
		line[i] = backup[i];
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*free_backup(char *backup)
{
	int		size;
	int		start;
	char	*tmp;

	start = 0;
	size = 0;
	if (backup == NULL)
		return (NULL);
	while (backup[start] != '\n' && backup[start] != '\0')
		start++;
	if (backup[start] == '\0' || backup[start + 1] == '\0')
	{
		free(backup);
		return (NULL);
	}
	while (backup[size] != '\0')
		size++;
	size -= start;
	tmp = backup;
	backup = ft_substr(tmp, start + 1, size);
	free (tmp);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (backup)
		{
			free(backup);
			backup = NULL;
		}
		return (NULL);
	}
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (ft_strchr(backup, '\n') == NULL)
		backup = read_line(fd, buf, backup);
	free(buf);
	buf = NULL;
	line = extract(backup);
	backup = free_backup(backup);
	return (line);
}
