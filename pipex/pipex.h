/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:24:31 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/10 17:24:09 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

void	child_one(char **ag, int *end, char **envp);
void	child_two(char **ag, int *end, char **envp);
char	*path_parcing(char *command, char **envp);
void	ft_execve(char *ag, char **envp);
void	ft_error(void);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t n);

#endif