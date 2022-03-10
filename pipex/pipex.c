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

void child_one(int f1, char *cmd1, int end, char **envp)
{
	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	ft_execve(cmd1, envp);
	exit(EXIT_FAILURE);
}

void child_two(int f2, char *cmd2, int end, char **envp)
{
	dup2(f2, STDIN_FILENO);
	dup2(end[0], STDOUT_FILENO);
	close(end[1]);
	ft_execve(cmd2, envp);
	exit(EXIT_FAILURE);
}

void ft_pipex(int f1, int f2, char *cmd1, char *cmd2, char **envp)
{
	int status;
	int end[2];

	pid_t child1;
	pid_t child2;

	if (pipe(end) == -1)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	};
	child1 = fork();
	if (child1 < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (!child1)
		child_one(f1, cmd1, end, envp);
	child2 = fork();
	if (child2 < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (!child2)
		child_two(f2, cmd2, end, envp);
	close(end[0]);				 
	close(end[1]);				 
	waitpid(child1, &status, 0); 
	waitpid(child2, &status, 0); 
}

int main(int ac, char *ag[], char **envp)
{
	int f1;
	int f2;
	char *cmd1;
	char *cmd2;

	cmd1 = ag[2];
	cmd2 = ag[3];

	if (ac != 5)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	f1 = open(ag[1], O_RDONLY);
	f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (f1 < 0 || f2 < 0)
	{
		perror("file error");
		exit(EXIT_FAILURE);
	}
	ft_pipex(f1, f2, cmd1, cmd2, envp);
	return (0);
}
