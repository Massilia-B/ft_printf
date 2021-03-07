/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_neg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:29:52 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:09:30 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_id_flag_neg(t_format *comb, int num, int *count, int l)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (num < 0)
	{
		num = num * -1;
		i += ft_id_flag_neg2(comb, l, num, &tmp);
		if (comb->lenght > l)
		{
			*count += i;
			i = 0;
		}
		while (i < (comb->width - tmp))
		{
			write(1, " ", 1);
			i++;
		}
		*count += i + l;
		return (1);
	}
	return (0);
}

int		ft_id_flag_neg2(t_format *comb, int l, int num, int *tmp)
{
	int	i;

	i = 0;
	write(1, "-", 1);
	while (i < (comb->lenght - (l - 1)))
	{
		write(1, "0", 1);
		i++;
	}
	if (l < comb->lenght)
		*tmp = comb->lenght + 1;
	else
		*tmp = l;
	if (num == -2147483648)
		write(1, "2147483648", 10);
	else
		ft_putnbr(num);
	return (i);
}

void	ft_id_width_neg(t_format *comb, int num, int *count, int l)
{
	int	i;

	i = 0;
	num = num * -1;
	write(1, "-", 1);
	while (i < (comb->width - l))
	{
		write(1, "0", 1);
		i++;
	}
	if (num == -2147483648)
		write(1, "2147483648", 10);
	else
		ft_putnbr(num);
	*count += i + l;
}

void	ft_id_prec_neg(t_format *comb, int num, int *count, int l)
{
	int	i;

	i = 0;
	num = num * -1;
	write(1, "-", 1);
	while (i < (comb->lenght - (l - 1)))
	{
		write(1, "0", 1);
		i++;
	}
	if (num == -2147483648)
		write(1, "2147483648", 10);
	else
		ft_putnbr(num);
	*count += i + l;
}
