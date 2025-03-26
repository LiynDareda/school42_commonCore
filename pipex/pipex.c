/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:36:21 by lbarlett          #+#    #+#             */
/*   Updated: 2024/07/01 13:57:23 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *pfd)
{
	int		fd;
	char	*tmp;
	char	**command;
	char	**env;

	tmp = NULL;
	command = NULL;
	env = NULL;
	dup2(pfd[1], 1);
	close(pfd[0]);
	fd = open(argv[1], O_RDONLY, 0644);
	if (fd == -1)
		ft_exit(1);
	dup2(fd, 0);
	tmp = my_get_env(&env, &command, envp, argv[2]);
	execve(tmp, command, envp);
	(void)(free_mat(env) + free_mat(command));
	free(tmp);
	ft_error(2);
}

void	parent_process(char **argv, char **envp, int *pfd)
{
	int		fd;
	char	**command;
	char	**env;
	char	*tmp;

	tmp = NULL;
	command = NULL;
	env = NULL;
	dup2(pfd[0], 0);
	close(pfd[1]);
	if (open(argv[4], O_DIRECTORY) != -1)
		ft_exit(4);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_exit(3);
	dup2(fd, 1);
	tmp = my_get_env(&env, &command, envp, argv[3]);
	execve(tmp, command, envp);
	(void)(free_mat(env) + free_mat(command));
	free(tmp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	pid_t	pid;

	if (argc != 5)
	{
		write(2, "bad arguments\n", 15);
		write(1, "Ex: ./pipex <file1> <cm1> <cm2> <file2>\n", 41);
		exit(0);
	}
	if (pipe(pfd) == -1)
		ft_error(8);
	pid = fork();
	if (pid == -1)
		ft_error(9);
	if (pid == 0)
		child_process(argv, envp, pfd);
	else
		parent_process(argv, envp, pfd);
	wait(NULL);
	wait(NULL);
	return (0);
}
