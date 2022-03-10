/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:29:19 by wdwain          #+#    #+#             */
/*   Updated: 2019/11/14 19:20:21 by wdwain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(char **ag, int *end, char **envp)
{
	int		f1;

	f1 = open(ag[1], O_RDONLY, 0777);
	if (f1 < 0)
		ft_error();
	if (dup2(f1, STDIN_FILENO) < 0)
		ft_error();
	if (dup2(end[1], STDOUT_FILENO) < 0)
		ft_error();
	close(f1);
	close(end[0]);
	ft_execve(ag[2], envp);
	ft_error();
}

void	child_two(char **ag, int *end, char **envp)
{
	int		f2;

	f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (f2 < 0)
		ft_error();
	if (dup2(end[0], STDIN_FILENO) < 0)
		ft_error();
	if (dup2(f2, STDOUT_FILENO) < 0)
		ft_error();
	close(f2);
	close(end[1]);
	ft_execve(ag[3], envp);
	ft_error();
}

int	main(int ac, char **ag, char **envp)
{
	int		end[2];
	pid_t	child1;
	pid_t	child2;

	if (ac == 5)
	{
		if (pipe(end) == -1)
			ft_error();
		child1 = fork();
		if (child1 == -1)
			ft_error();
		if (!child1)
			child_one(ag, end, envp);
		child2 = fork();
		if (child2 == -1)
			ft_error();
		if (!child2)
			child_two(ag, end, envp);
		close(end[0]);
		close(end[1]);
		waitpid(child1, NULL, 0);
		waitpid(child2, NULL, 0);
	}
	else
		ft_error();
}
