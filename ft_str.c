/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:40:31 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:07:34 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_flag(t_format *comb, char *str, int *count)
{
	int	i;
	int	tmp;
	int	l;

	l = ft_strlen(str);
	tmp = 0;
	if (comb->prec == '.' && comb->lenght < l && comb->flag_pr != '-')
		tmp = comb->lenght;
	else
		tmp = l;
	i = 0;
	while (str[i] && i < tmp)
	{
		write(1, &str[i], 1);
		i++;
	}
	while (i < (comb->width))
	{
		write(1, " ", 1);
		i++;
	}
	*count += i;
}

void	ft_str_width(t_format *comb, char *str, int *count)
{
	int	l;
	int	i;

	l = ft_strlen(str);
	if (comb->zero == 0)
		i = ft_write_zero(comb->width, l, 0);
	else
		i = ft_write_space(comb->width, l, 0);
	*count += i;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	*count += i;
}

void	ft_str_prec2(t_format *comb, char *str, int *count, int tmp)
{
	int	i;
	int	l;

	l = ft_strlen(str);
	if (comb->flag_pr == '-')
		tmp = l;
	else
		tmp = comb->lenght;
	i = 0;
	while (str[i] && i < tmp)
	{
		write(1, &str[i], 1);
		i++;
	}
	*count += i;
}

void	ft_str_prec(t_format *comb, char *str, int *count, int s)
{
	int	l;
	int	tmp;

	l = ft_strlen(str);
	tmp = 0;
	if (s == 1 && comb->width != 0 && comb->lenght == 0)
		str = ft_strdup(" ");
	if (comb->flag_pr == '-' && comb->width != 0)
		*count += ft_write_space(comb->width, l, 0);
	else if (comb->flag_pr != '-')
	{
		if (l < comb->lenght)
			tmp = l;
		else
			tmp = comb->lenght;
		*count += ft_write_space(comb->width, tmp, 0);
	}
	ft_str_prec2(comb, str, count, tmp);
}
