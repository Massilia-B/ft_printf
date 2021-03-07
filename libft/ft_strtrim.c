/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:31:59 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 18:05:13 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findset(char const *s1, char j)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == j)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	char	*s2;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	first = 0;
	while (s1[first] && ft_findset(set, s1[first]))
		first++;
	end = ft_strlen(s1);
	while (end > first && ft_findset(set, s1[end - 1]))
		end--;
	if (!(s2 = (char *)malloc(sizeof(char) * ((end - first) + 1))))
		return (NULL);
	i = 0;
	while (first < end)
		s2[i++] = s1[first++];
	s2[i++] = '\0';
	return (s2);
}
