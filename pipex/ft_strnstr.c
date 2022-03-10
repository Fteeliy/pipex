/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:52:40 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/10 18:23:58 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[i])
		return ((char *) big);
	while (i < n && big[i])
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j] && i + j < n)
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return ((char *) NULL);
}
