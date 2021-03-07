/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:38:45 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:07:01 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	ft_init(void)
{
	t_format comb;

	comb.flag = 0;
	comb.width = 0;
	comb.spec = 0;
	comb.prec = 0;
	comb.lenght = 0;
	comb.lenght_str = -1;
	comb.zero = -1;
	comb.flag_pr = 0;
	comb.zero_pr = -1;
	return (comb);
}

int			ft_pars(char *format, va_list *args, int *count)
{
	int			i;
	t_format	comb;

	comb = ft_init();
	i = 0;
	if (ft_get_zero(format + i, &comb))
		i++;
	if (ft_get_sign(format + i, &comb))
		i++;
	if (ft_get_zero(format + i, &comb) || ft_get_sign(format + i, &comb))
	{
		i++;
		while (*(format + i) == '-' || *(format + i) == '0')
			i++;
	}
	i += ft_pars2(format + i, &comb, args);
	if (ft_get_conv(format + i, &comb))
		i++;
	check_conv(&comb, args, count);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	int			c;

	va_start(args, format);
	count = 0;
	c = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			c = ft_pars((char *)format, &args, &count);
			format += c - 1;
		}
		else
		{
			write(1, *&format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
