/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:02:59 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/10 11:59:05 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(char **argv, int *fdp, char **envp)
{
	int		fd;
	char	**cmd;
	char	*path;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		file_error(argv[1]);
	cmd = ft_split(argv[2], ' ');
	path = get_path(cmd[0], envp);
	if (!path)
		cmd_error(cmd[0], cmd);
	close(fdp[0]);
	dup2(fdp[1], 1);
	dup2(fd, 0);
	close(fd);
	execve(path, cmd, envp);
	error_msg("error with execve:");
}

void	child_two(char **argv, int *fdp, char **envp)
{
	int		fd;
	char	**cmd;
	char	*path;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		file_error(argv[4]);
	cmd = ft_split(argv[3], ' ');
	path = get_path(cmd[0], envp);
	if (!path)
		cmd_error(cmd[0], cmd);
	close(fdp[1]);
	dup2(fdp[0], 0);
	dup2(fd, 1);
	close(fd);
	execve(path, cmd, envp);
	error_msg("error with execve:");
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd_pipe[2];
	int		status;

	if (argc != 5)
		error_msg("Incorrect Syntax!");
	if (pipe(fd_pipe) == -1)
		error_msg("pipe:");
	pid1 = fork();
	if (pid1 == -1)
		error_msg("fork:");
	if (pid1 == 0)
		child_one(argv, fd_pipe, envp);
	pid2 = fork();
	if (pid2 == -1)
		error_msg("fork:");
	if (pid2 == 0)
		child_two(argv, fd_pipe, envp);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	exit(WEXITSTATUS(status));
}
