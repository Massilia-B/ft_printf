/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:56:24 by user42            #+#    #+#             */
/*   Updated: 2020/11/19 13:07:53 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_length(long int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*final_n;
	int		size;
	int		i;
	long	nb;

	nb = n;
	size = ft_length(nb);
	if (!(final_n = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (nb < 0)
	{
		final_n[0] = '-';
		nb *= -1;
	}
	i = size - 1;
	while (nb >= 10)
	{
		final_n[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	final_n[i] = nb % 10 + 48;
	final_n[size] = '\0';
	return (final_n);
}
