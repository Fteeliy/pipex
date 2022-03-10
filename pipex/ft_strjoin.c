/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:37:39 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/10 18:23:53 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	s_len;

	if (s1 == NULL || s2 == NULL)
		return ((char *) NULL);
	s_len = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	s = (char *)malloc(sizeof(char) * s_len);
	if (!s)
		return ((char *) NULL);
	i = 0;
	while (*s1)
	{
		s[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		s[i++] = *s2;
		s2++;
	}
	s[i] = '\0';
	return (s);
}
