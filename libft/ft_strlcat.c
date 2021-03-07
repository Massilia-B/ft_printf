/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:01:39 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 16:19:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l_src;
	size_t	l_dst;

	l_src = ft_strlen(src);
	l_dst = ft_strlen(dst);
	j = l_dst;
	i = 0;
	if (l_dst < (size - 1) && size > 0)
	{
		while (src[i] && (l_dst + i) < (size - 1))
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (l_dst >= size)
		l_dst = size;
	return (l_dst + l_src);
}
