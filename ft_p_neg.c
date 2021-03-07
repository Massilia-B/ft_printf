/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_neg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:37:58 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:09:36 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_neg_prec(t_format *comb, int *count, char *hexa, char *num)
{
	int	tmp;
	int	l;
	int	i;

	l = ft_strlen(num);
	if (comb->prec == '.' && comb->lenght == 0)
		tmp = 2;
	else
		tmp = comb->lenght;
	if (comb->width != 0)
		*count += ft_write_space(comb->width, tmp, 0);
	ft_putstr(hexa);
	*count += 2;
	if (comb->lenght > l)
		*count += ft_write_zero(comb->width, tmp, 0);
	if (comb->width == 0 && comb->flag_pr != '-')
		*count += ft_write_zero(comb->lenght, l, 0);
	if (comb->prec == '.' && comb->lenght == 0)
		tmp = 0;
	i = 0;
	while (num[i] && i < tmp)
		write(1, &num[i++], 1);
	*count += i;
	free(hexa);
	free(num);
}
