/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:31:07 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 14:31:12 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_checkbase(long long n, int len)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n / len != 0)
	{
		size++;
		n /= len;
	}
	return (size + 1);
}

static void		ft_swap(char *s, int size)
{
	char c;

	if (size > 1)
	{
		c = s[0];
		s[0] = s[size - 1];
		s[size - 1] = c;
		ft_swap(&s[1], size - 2);
	}
}

static void		ft_op(long long n, char *s, int len, char *base)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		s[i] = base[0];
		i++;
	}
	while (n != 0)
	{
		s[i] = base[n % len];
		n /= len;
		i++;
	}
	s[i] = '\0';
}

char			*ft_itoa_base(long long n, char *base)
{
	char	*s;
	int		size;
	int		len;

	if (n < 0)
		n *= -1;
	len = (int)ft_strlen(base);
	size = ft_checkbase(n, len);
	s = (char*)malloc(sizeof(char) * (size + 1));
	if (s == 0)
		return (0);
	ft_op(n, s, len, base);
	ft_swap(s, size);
	return (s);
}
