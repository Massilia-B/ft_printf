/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:28:21 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:20:54 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_flag(t_format *comb, va_list *args, int *count)
{
	int i;

	i = 0;
	ft_putchar((char)va_arg(*args, int));
	while (i < (comb->width - 1))
	{
		write(1, " ", 1);
		i++;
	}
	*count += i + 1;
}

void	ft_char_width(t_format *comb, va_list *args, int *count)
{
	int	i;

	i = 0;
	while (i < (comb->width - 1))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putchar((char)va_arg(*args, int));
	*count += i + 1;
}

void	ft_char_prec(t_format *comb, va_list *args, int *count)
{
	int i;

	i = 0;
	while (i < comb->width - 1)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putchar((char)va_arg(*args, int));
	*count += i + 1;
}
