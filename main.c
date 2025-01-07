/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:20:00 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/07 11:43:49 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_exit(char *msg, t_pipex *pipex)
{
	free_pipex(pipex);
	error_exit(msg);
}

void	child_one(t_pipex *pipex, char *infile)
{
	int	infile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd < 0)
		free_exit("Infile error", pipex);
	close(pipex->pipe_fd[0]);
	dup2(infile_fd, STDIN_FILENO);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[1]);
	close(infile_fd);
	if (!pipex->cmd1_path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(pipex->cmd1_args[0], 2);
		free_pipex(pipex);
		exit(127);
	}
	if (execve(pipex->cmd1_path, pipex->cmd1_args, pipex->envp) == -1)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(pipex->cmd1_args[0], 2);
		free_pipex(pipex);
		exit(127);
	}
}

void	child_two(t_pipex *pipex, char *outfile)
{
	int	outfile_fd;

	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		free_exit("Outfile error", pipex);
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(outfile_fd);
	if (!pipex->cmd2_path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(pipex->cmd2_args[0], 2);
		free_pipex(pipex);
		exit(127);
	}
	if (execve(pipex->cmd2_path, pipex->cmd2_args, pipex->envp) == -1)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(pipex->cmd2_args[0], 2);
		free_pipex(pipex);
		exit(127);
	}
}

void	parent_process(t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, &pipex->status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (error_msg("./pipex infile cmd1 cmd2 outfile"));
	init_pipex(&pipex, argv, envp);
	if (pipe(pipex.pipe_fd) < 0)
		error_exit("Pipe error");
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child_one(&pipex, argv[1]);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		child_two(&pipex, argv[4]);
	parent_process(&pipex);
	free_pipex(&pipex);
	return (WEXITSTATUS(pipex.status));
}
