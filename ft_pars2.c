/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:38:18 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:24:03 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pars2(char *format, t_format *comb, va_list *args)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	if ((count = is_num(format + j, comb, args)) != -1)
		j += count;
	if (ft_get_prec(format + j, comb))
	{
		j++;
		if (format[j] == '0')
		{
			comb->zero_pr = 0;
			j++;
		}
		if (format[j] == '-')
		{
			comb->flag_pr = '-';
			j++;
		}
		if ((count = is_num_prec(format + j, comb, args)) != -1)
			j += count;
	}
	return (j);
}
