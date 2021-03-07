/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:00:41 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 16:58:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;
	int	neg;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (neg == 1)
			{
				count++;
				neg = 0;
			}
		}
		else
			neg = 1;
		i++;
	}
	if (neg == 1)
		count++;
	return (count);
}

static int	letters_c(char const *s, char c, int k)
{
	int i;

	i = 0;
	while (s[k] && s[k] != c)
	{
		k++;
		i++;
	}
	return (i);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dest;

	if (!(dest = (char **)malloc(sizeof(char*) * (ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < ft_count(s, c))
	{
		j = 0;
		if (c && s[k] != c)
		{
			dest[i] = (char *)malloc(sizeof(char) * (letters_c(s, c, k) + 1));
			while (s[k] != c)
				dest[i][j++] = s[k++];
			dest[i][j] = '\0';
			i++;
		}
		else
			k++;
	}
	dest[i] = 0;
	return (dest);
}
