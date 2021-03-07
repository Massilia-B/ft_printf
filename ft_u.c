/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:40:52 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:24:50 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_flag(t_format *comb, unsigned int num, int *count)
{
	int l;
	int tmp;
	int i;

	l = ft_len_unsigned(num);
	tmp = 0;
	i = 0;
	tmp = ft_tmp(comb, l, tmp);
	if (comb->flag_pr != '-')
		*count += ft_write_zero(comb->lenght, l, 0);
	if (ft_u_zero(num, comb, count) == 1)
		return ;
	*count += ft_u_flag2(comb, num, &tmp, l);
	if (comb->prec == '.' && comb->flag_pr != '-'
	&& num != 0 && comb->zero == 0 && comb->width < tmp)
		i = ft_write_zero(comb->width, l, 0);
	else
		i += ft_write_space(comb->width, tmp, 0);
	*count += i;
}

int		ft_u_flag2(t_format *comb, unsigned int num, int *tmp, int l)
{
	if (ft_write_only(num, comb) == 1)
		l = 1;
	else
	{
		ft_putnbr_unsigned(num);
		if (comb->flag == '-' && comb->prec == '.' && comb->flag_pr == '-')
			*tmp = l;
	}
	return (l);
}

void	ft_u_width(t_format *comb, unsigned int num, int *count)
{
	int	l;

	l = ft_len_unsigned(num);
	if (comb->zero == 0)
	{
		*count += ft_write_zero(comb->width, l, 0);
		ft_putnbr_unsigned(num);
	}
	else
	{
		*count += ft_write_space(comb->width, l, 0);
		ft_putnbr_unsigned(num);
	}
	*count += l;
}

void	ft_u_prec2(t_format *comb, unsigned int num, int *count, int tmp)
{
	int	l;

	l = ft_len_unsigned(num);
	if (comb->width != 0)
	{
		if (comb->zero == 0 && comb->flag_pr == '-')
		{
			ft_u_width(comb, num, count);
			return ;
		}
		*count += ft_write_space(comb->width, tmp, 0);
		if (num == 0 && comb->lenght == 0)
		{
			write(1, " ", 1);
			*count += 1;
			return ;
		}
	}
	else if (comb->width == 0 && num == 0 && comb->lenght == 0)
		return ;
	if (comb->flag_pr != '-')
		*count += ft_write_zero(comb->lenght, l, 0);
	ft_putnbr_unsigned(num);
	*count += l;
}

void	ft_u_prec(t_format *comb, unsigned int num, int *count)
{
	int	l;
	int	tmp;

	l = ft_len_unsigned(num);
	tmp = 0;
	if (ft_write_only_pr(num, comb, count) == 1)
		return ;
	if (comb->flag_pr == '-' && comb->lenght != 0)
		tmp = l;
	else
		tmp = ft_tmp(comb, l, tmp);
	ft_u_prec2(comb, num, count, tmp);
}
