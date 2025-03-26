/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lbarlett <lbarlett@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/10 17:19:25 by lbarlett		  #+#	#+#			 */
/*   Updated: 2023/11/15 12:17:56 by lbarlett		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

	#ifndef BUFFER_SIZE
		#define BUFFER_SIZE 50
	#endif
	

	# include <stdlib.h>
	# include <unistd.h>

	int	 ft_strlen(const char *str);
	char	*ft_strchr(const char *s, int i);
	char	*ft_strdup(const char *s);
	char	*ft_strjoin(char const *s1, char const *s2);
	char	*next_line(int fd, char *buffer, char *buffer_static);
	char	*ft_calloc(size_t nmemb, size_t size);
	char	*extract(char *buffer_static);
	char	*get_next_line(int fd);

#endif