/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:55:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 15:55:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, size_t size)
{
	char *p;

	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	if (!(p = (void *)malloc(sizeof(char) * (count * size))))
		return (NULL);
	if (p == 0)
		return (0);
	ft_bzero(p, (count * size));
	return (p);
}
