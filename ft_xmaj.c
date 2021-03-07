/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Xmaj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:25:28 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:08:31 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_xmaj_flag(t_format *comb, char *str, int *count, unsigned int num)
{
	int	i;
	int	l;
	int	tmp;

	l = ft_strlen(str);
	i = 0;
	if (comb->flag_pr != '-')
		i = ft_write_zero(comb->lenght, l, i);
	*count += i;
	tmp = ft_x_flag2(comb, str, count, num);
	i = 0;
	if (comb->width != 0 || (comb->prec == '.'
	&& comb->width != 0 && comb->lenght != 0))
		i = ft_write_space(comb->width, tmp, i);
	*count += i;
}

int		ft_xmaj_flag2(t_format *comb, char *str, int *count, unsigned int num)
{
	int	l;
	int tmp;

	l = ft_strlen(str);
	if (l < comb->lenght)
		tmp = comb->lenght;
	else
		tmp = l;
	if (comb->width != 0 && num == 0 && comb->lenght == 0 && comb->prec == '.')
	{
		write(1, " ", 1);
		l = 1;
	}
	else if (!(num == 0 && comb->lenght == 0 && comb->prec == '.'))
	{
		ft_putstr(str);
		if (comb->flag == '-' && comb->prec == '.' && comb->flag_pr == '-')
			tmp = l;
	}
	else
		l = 0;
	*count += l;
	return (tmp);
}

void	ft_xmaj_width(t_format *comb, char *str, int *count)
{
	int	i;
	int	l;

	l = ft_strlen(str);
	i = 0;
	if (comb->zero == 0)
		i += ft_write_zero(comb->width, l, i);
	else
		i += ft_write_space(comb->width, l, i);
	ft_putstr(str);
	*count += i + l;
}

void	ft_xmaj_prec(t_format *comb, char *str, int *count, unsigned int num)
{
	int	l;
	int i;

	i = 0;
	l = ft_strlen(str);
	if (comb->flag_pr == '-' && num == 0 && comb->lenght == 0)
	{
		write(1, "0", 1);
		*count += 1;
		return ;
	}
	if (comb->flag_pr == '-')
	{
		ft_x_width(comb, str, count);
		return ;
	}
	if ((l = ft_x_prec2(comb, count, num, l)) == -1)
		return ;
	i = ft_write_zero(comb->lenght, l, i);
	*count += i;
	if (num == 0 && comb->width == 0 && comb->lenght != 0)
		return ;
	else
		ft_putstr(str);
	*count += l;
}

int		ft_xmaj_prec2(t_format *comb, int *count, unsigned int num, int l)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	if (comb->width == 0 && num == 0 && comb->lenght != 0)
		l = 0;
	tmp = ft_tmp(comb, l, tmp);
	if (comb->width != 0)
		i += ft_write_space(comb->width, tmp, i);
	*count += i;
	if (num == 0 && comb->lenght == 0)
	{
		if (comb->width != 0)
		{
			write(1, " ", 1);
			*count += 1;
		}
		return (-1);
	}
	return (l);
}
