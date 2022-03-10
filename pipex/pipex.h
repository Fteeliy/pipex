/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:24:31 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/10 13:57:24 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

void	child_one(int f1, char *cmd1, int end, char **envp);
void	child_two(int f2, char *cmd2, int end, char **envp);
void	ft_pipex(int f1, int f2, char *cmd1, char *cmd2, char **envp);
void	ft_execve(char *ag, char **envp);
char	*path_parsing(char *command, char **envp);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif