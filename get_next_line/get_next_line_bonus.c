/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_bonus.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lbarlett <lbarlett@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/15 12:17:24 by lbarlett		  #+#	#+#			 */
/*   Updated: 2023/11/15 13:58:30 by lbarlett		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*next_line(int fd, char *buffer, char *buffer_static)
{
	int		read_line;
	char	*tmp;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line < 0)
			return (NULL);
		else if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		if (!buffer_static)
			buffer_static = ft_strdup("");
		tmp = ft_strjoin(buffer_static, buffer);
		if (!tmp)
			return (NULL);
		free(buffer_static);
		buffer_static = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer_static);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char		*arr;
	long long	result;
	size_t		i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	result = (long long)nmemb * (long long)size;
	if (result > 4294967295)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < (size * nmemb))
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}
char	*extract(char *buffer_static)
{
	size_t	count;
	size_t	i;
	char	*line;

	count = 0;
	if (!buffer_static)
		return (NULL);
	while (buffer_static[count] != '\n' && buffer_static[count] != '\0')
		count++;
	line = ft_calloc(count + 1 + (buffer_static[count] == '\n'), sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while(buffer_static[++i] != '\n' && buffer_static[i] != '\0')
		line[i] = buffer_static[i];
	if (buffer_static[i] == '\n')
		line[i] = '\n';
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
char	*clear_buffer(char *buffer_static)
{
	char	*tmp;
	int		start;
	int		count;

	start = 0;
	if(!buffer_static)
		return (NULL);
	while (buffer_static[start] != '\n' && buffer_static[start] != '\0')
		start++;
	if (buffer_static[start] == '\0')
	{
		free(buffer_static);
		return (NULL);
	}
	count = start + 1;
	while (buffer_static[count] != '\0')
		count++;
	tmp = ft_calloc(count - start + 1, sizeof(char));
	if(!tmp)
		return (NULL);
	count = 0;
	while (buffer_static[start + 1] != '\0')
		tmp[count++] = buffer_static[(start++) + 1];
	free(buffer_static);
	return (tmp);	
}
char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*buffer_static[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer_static[fd] != NULL)
		{
			free(buffer_static[fd]);
			buffer_static[fd] = NULL;
		}
		return (NULL);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	buffer_static[fd] = next_line(fd, buffer, buffer_static[fd]);
	free(buffer);
	line = extract(buffer_static[fd]);
	if (!line)
		return (NULL);
	buffer_static[fd] = clear_buffer(buffer_static[fd]);
	return (line);
}