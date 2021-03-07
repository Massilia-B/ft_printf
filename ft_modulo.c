/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modulo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:31:26 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:09:32 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mod_flag(t_format *comb, int *count)
{
	ft_putchar('%');
	*count += ft_write_space(comb->width, 1, 0);
	*count += 1;
}

void	ft_mod_width(t_format *comb, int *count)
{
	if (comb->lenght == 0 && comb->width == 0)
	{
		write(1, "%%", 1);
		*count += 1;
		return ;
	}
	if (comb->zero == 0)
		*count += ft_write_zero(comb->width, 1, 0);
	else
		*count += ft_write_space(comb->width, 1, 0);
	write(1, "%%", 1);
	*count += 1;
}

void	ft_mod_prec(t_format *comb, int *count)
{
	int i;

	i = 0;
	if (comb->zero == 0)
		i = ft_write_zero(comb->width, 1, i);
	else
		i = ft_write_space(comb->width, 1, i);
	ft_putchar('%');
	*count += i + 1;
}
