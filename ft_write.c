/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:41:18 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:07:55 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_u_zero(unsigned int num, t_format *comb, int *count)
{
	if (comb->prec == '.' && num == 0 && comb->zero == 0
	&& comb->zero_pr == 0)
		return (1);
	else if (comb->prec == '.' && num == 0 && comb->lenght == 0
	&& comb->width == 0)
	{
		write(1, " ", 1);
		*count += 1;
		return (1);
	}
	return (0);
}

int		ft_write_only(unsigned int num, t_format *comb)
{
	if (num == 0 && comb->lenght == 0 && comb->prec == '.')
	{
		write(1, " ", 1);
		return (1);
	}
	return (0);
}

int		ft_write_only_pr(unsigned int num, t_format *comb, int *count)
{
	if (comb->flag_pr == '-' && num == 0 && comb->lenght == 0
	&& comb->width == 0)
	{
		write(1, "0", 1);
		*count += 1;
		return (1);
	}
	return (0);
}

int		ft_write_zero(int len, int tmp, int i)
{
	while (i < (len - tmp))
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int		ft_write_space(int len, int tmp, int i)
{
	while (i < (len - tmp))
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}
