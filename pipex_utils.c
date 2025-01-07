/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:22:24 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/06 21:33:14 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *message)
{
	perror(message);
	exit(1);
}

void	free_pipex(t_pipex *pipex)
{
	free_strs(pipex->cmd1_args);
	free_strs(pipex->cmd2_args);
	if (pipex->cmd1_path)
		free(pipex->cmd1_path);
	if (pipex->cmd2_path)
		free(pipex->cmd2_path);
}

int	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (1);
}

void	init_pipex(t_pipex *pipex, char **argv, char **envp)
{
	pipex->cmd1_args = ft_split(argv[2], ' ');
	pipex->cmd2_args = ft_split(argv[3], ' ');
	pipex->cmd1_path = get_path(pipex->cmd1_args[0], envp);
	pipex->cmd2_path = get_path(pipex->cmd2_args[0], envp);
	pipex->envp = envp;
}
