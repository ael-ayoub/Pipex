/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:02:53 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/10 12:00:51 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	child_one(char **argv, int *fdp, char **envp);
void	child_two(char **argv, int *fdp, char **envp);
char	*get_path(char *cmd, char **envp);
int		error_msg(char *msg);
void	file_error(char *file_name);
void	cmd_error(char *cmd0, char **cmd);
void	free_strs(char **strs);

#endif
