/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:40:26 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/07 11:40:27 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct t_pipex
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd1_args;
	char	**cmd2_args;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**envp;
	int		status;
}			t_pipex;

char		*get_path(char *command, char **envp);
void		free_strs(char **strs);
void		error_exit(char *message);
void		free_pipex(t_pipex *pipex);
int			error_msg(char *msg);
void		init_pipex(t_pipex *pipex, char **argv, char **envp);

#endif
