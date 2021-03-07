/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:31:52 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:09:34 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_len(int num)
{
	int			size;
	long int	n;

	n = (long int)num;
	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		size++;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

unsigned int	ft_len_unsigned(unsigned int num)
{
	unsigned int	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

int				is_num(char *format, t_format *comb, va_list *args)
{
	int	num;

	if (*format >= 48 && *format <= 57)
	{
		comb->width = ft_atoi(format);
		num = ft_len(comb->width);
		return (num);
	}
	else if (*format == '*')
	{
		comb->width = (int)va_arg(*args, int);
		if (comb->width == 0)
			comb->zero = 0;
		if (comb->width < 0)
		{
			comb->width = comb->width * -1;
			comb->flag = '-';
			if (comb->zero == 0)
				comb->zero = -1;
		}
		return (1);
	}
	return (-1);
}

int				is_num_prec(char *format, t_format *comb, va_list *args)
{
	int num;

	if (*format >= 48 && *format <= 57)
	{
		comb->lenght = ft_atoi(format);
		num = ft_len(comb->lenght);
		return (num);
	}
	else if (*format == '*')
	{
		comb->lenght = (int)va_arg(*args, int);
		if (comb->lenght == 0)
			comb->zero_pr = 0;
		if (comb->lenght < 0)
		{
			comb->lenght = comb->lenght * -1;
			comb->flag_pr = '-';
			comb->zero_pr = -1;
		}
		return (1);
	}
	return (-1);
}

int				ft_tmp(t_format *comb, int l, int tmp)
{
	if (comb->lenght > l)
		tmp = comb->lenght;
	else
		tmp = l;
	return (tmp);
}
