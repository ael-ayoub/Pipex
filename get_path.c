/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 22:16:58 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/01/10 12:09:09 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	if (strs)
		free(strs);
	strs = NULL;
}

char	*get_path_2(char **envp)
{
	int		index;
	char	*path;

	index = 0;
	while (envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
		{
			path = ft_strdup(5 + envp[index]);
			return (path);
		}
		index++;
	}
	return (NULL);
}

char	*check_access(char **envps, char *command)
{
	int		i;
	char	*path_1;
	char	*path;

	i = -1;
	while (envps[++i])
	{
		path_1 = ft_strjoin(envps[i], "/");
		path = ft_strjoin(path_1, command);
		free(path_1);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
		{
			free_strs(envps);
			return (path);
		}
		free(path);
	}
	free_strs(envps);
	return (0);
}

char	*get_path(char *command, char **envp)
{
	char	*all_path;
	char	**envps;
	char	*path;

	if (!*envp || !command)
		return (NULL);
	all_path = get_path_2(envp);
	if (all_path)
	{
		envps = ft_split(all_path, ':');
		free(all_path);
	}
	else
		return (0);
	path = check_access(envps, command);
	if (path)
		return (path);
	return (0);
}
