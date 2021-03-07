/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:15:22 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:22:12 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_id_flag(t_format *comb, int num, int *count)
{
	int l;
	int tmp;

	l = ft_len(num);
	tmp = 0;
	if (num == 0 && comb->prec == '.'
	&& (!(comb->lenght != 0 || comb->width != 0)))
		return ;
	if (comb->flag_pr == '-')
		comb->lenght = -1;
	tmp = ft_tmp(comb, l, tmp);
	if (ft_id_flag_neg(comb, num, count, l) == 1)
		return ;
	if (num == 0 && comb->lenght == 0 && comb->prec == '.')
	{
		write(1, " ", 1);
		l = 1;
	}
	else
	{
		*count += ft_write_zero(comb->lenght, l, 0);
		ft_putnbr(num);
	}
	*count += ft_write_space(comb->width, tmp, 0);
	*count += l;
}

void	ft_id_width(t_format *comb, int num, int *count)
{
	int	l;

	l = ft_len(num);
	if (comb->zero == 0)
	{
		if (num < 0)
		{
			ft_id_width_neg(comb, num, count, l);
			return ;
		}
		*count += ft_write_zero(comb->width, l, 0);
	}
	else
		*count += ft_write_space(comb->width, l, 0);
	ft_putnbr(num);
	*count += l;
}

void	ft_id_prec3(t_format *comb, int num, int *count, int l)
{
	if (num == 0 && comb->lenght == 0)
	{
		write(1, " ", 1);
		l = 1;
	}
	else
	{
		*count += ft_write_zero(comb->lenght, l, 0);
		ft_putnbr(num);
	}
	*count += l;
	return ;
}

void	ft_id_prec2(t_format *comb, int num, int *count, int l)
{
	int tmp;
	int i;

	tmp = 0;
	tmp = ft_tmp(comb, l, tmp);
	i = 0;
	if (comb->width != 0)
	{
		if (num < 0 && tmp == comb->lenght)
			tmp++;
		i = ft_write_space(comb->width, tmp, i);
		if (comb->zero == 0)
			i = ft_write_zero(comb->width, tmp, i);
		*count += i;
	}
	return ;
}

void	ft_id_prec(t_format *comb, int num, int *count)
{
	int l;

	l = ft_len(num);
	if (comb->flag_pr == '-')
	{
		ft_id_width(comb, num, count);
		return ;
	}
	if (num == 0 && (!(comb->lenght != 0 || comb->width != 0)))
		return ;
	ft_id_prec2(comb, num, count, l);
	if (num < 0)
	{
		ft_id_prec_neg(comb, num, count, l);
		return ;
	}
	ft_id_prec3(comb, num, count, l);
}
