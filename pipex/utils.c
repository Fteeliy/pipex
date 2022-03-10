/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:52:40 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/10 18:43:20 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

char	*path_parcing(char *command, char **envp)
{
	char	**mypaths;
	char	*onepath;
	char	*path;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	mypaths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (mypaths[i])
	{
		onepath = ft_strjoin(mypaths[i], "/");
		path = ft_strjoin(onepath, command);
		free(onepath);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	ft_execve(char *ag, char **envp)
{
	char	**command;
	char	*path;

	command = ft_split(ag, ' ');
	path = path_parcing(command[0], envp);
	if (execve(path, command, envp) == -1)
		ft_error();
}
