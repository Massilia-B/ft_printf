/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:36:59 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:09:35 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_flag(t_format *comb, unsigned long add, int *count)
{
	char	*hexa;
	char	*num;
	char	*str;
	int		l;

	hexa = ft_strdup("0x");
	num = ft_itoa_base(add, "0123456789abcdef");
	str = ft_strjoin(hexa, num);
	l = ft_strlen(str);
	ft_putstr(str);
	if (comb->width != 0)
		*count += ft_write_space(comb->width, l, 0);
	*count += l;
	free(hexa);
	free(num);
	free(str);
}

void	ft_p_width(t_format *comb, unsigned long add, int *count)
{
	char	*hexa;
	char	*num;
	char	*str;
	int		l;

	hexa = ft_strdup("0x");
	num = ft_itoa_base(add, "0123456789abcdef");
	str = ft_strjoin(hexa, num);
	l = ft_strlen(str);
	if (comb->width != 0)
		*count += ft_write_space(comb->width, l, 0);
	ft_putstr(str);
	*count += l;
	free(hexa);
	free(num);
	free(str);
}

void	ft_p_prec2(t_format *comb, int *count, char *num, int i)
{
	int	l;

	l = ft_strlen(num) + 2;
	if (comb->width == 0 && comb->flag_pr != '-')
		*count += ft_write_zero(comb->lenght, l, i);
	if (comb->prec == '.' && comb->lenght == 0)
		l = 0;
	i = 0;
	while (num[i] && i < l)
	{
		write(1, &num[i], 1);
		i++;
	}
	*count += i;
}

void	ft_p_prec(t_format *comb, unsigned long add, int *count)
{
	char	*hexa;
	char	*num;
	int		l;
	int		i;

	hexa = ft_strdup("0x");
	num = ft_itoa_base(add, "0123456789abcdef");
	l = ft_strlen(num) + 2;
	if (add == 0)
	{
		ft_p_neg_prec(comb, count, hexa, num);
		return ;
	}
	if (comb->width != 0)
		*count += ft_write_space(comb->width, l, 0);
	ft_putstr(hexa);
	*count += 2;
	i = 0;
	if (comb->lenght > l && comb->flag_pr != '-')
		i = ft_write_zero(comb->lenght, l - 2, i);
	*count += i;
	ft_p_prec2(comb, count, num, i);
	free(hexa);
	free(num);
}
