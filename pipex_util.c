/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:03:08 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/10 00:03:09 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	file_error(char *file_name)
{
	perror(file_name);
	exit(1);
}

void	cmd_error(char *cmd0, char **cmd)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(cmd0, 2);
	free_strs(cmd);
	exit(127);
}
