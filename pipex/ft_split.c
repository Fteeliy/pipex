/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:24:31 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/10 13:57:59 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_word_counter(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

char	*ft_word_split_sort(char const *s, char c)
{
	char	*word;
	int		k;

	k = 0;
	while (*s && *s == c)
		s++;
	while (s[k] && s[k] != c)
		k++;
	word = (char *)malloc(sizeof(char) * (k + 1));
	if (word == 0)
		return (NULL);
	k = 0;
	while (s[k] && s[k] != c)
	{
		word[k] = s[k];
		k++;
	}
	word[k] = '\0';
	return (word);
}

void	ft_free_str(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_str;
	int		strnbr;
	int		k;

	k = 0;
	if (!s)
		return (NULL);
	strnbr = ft_word_counter(s, c);
	splited_str = (char **)malloc(sizeof(char *) * (strnbr + 1));
	if (splited_str == 0)
		return (NULL);
	while (k < strnbr)
	{
		while (*s && *s == c)
			s++;
		splited_str[k] = ft_word_split_sort(s, c);
		if (splited_str == 0)
			ft_free_str(k, splited_str);
		while (*s && *s != c)
			s++;
		k++;
	}
	splited_str[k] = NULL;
	return (splited_str);
}