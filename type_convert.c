/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:43:16 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:08:45 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_id(t_format *comb, va_list *args, int *count)
{
	int num;

	num = va_arg(*args, int);
	if (comb->flag == '-')
		ft_id_flag(comb, num, count);
	else if (comb->prec == '.')
		ft_id_prec(comb, num, count);
	else if (!(comb->prec == '.') && !(comb->flag == '-'))
		ft_id_width(comb, num, count);
}

void	type_u(t_format *comb, va_list *args, int *count)
{
	unsigned int	num;

	num = (unsigned int)va_arg(*args, int);
	if (comb->flag == '-')
		ft_u_flag(comb, num, count);
	else if (comb->prec == '.')
		ft_u_prec(comb, num, count);
	else if (!(comb->prec == '.') && !(comb->flag == '-'))
		ft_u_width(comb, num, count);
}

void	type_x(t_format *comb, va_list *args, int *count)
{
	unsigned int	num;
	char			*str;

	num = (unsigned int)va_arg(*args, int);
	str = ft_itoa_base(num, "0123456789abcdef");
	if (comb->flag == '-')
		ft_x_flag(comb, str, count, num);
	else if (comb->prec == '.')
		ft_x_prec(comb, str, count, num);
	else if (!(comb->flag == '-') || !(comb->prec == '.'))
		ft_x_width(comb, str, count);
	free(str);
}

void	type_xmaj(t_format *comb, va_list *args, int *count)
{
	unsigned int	num;
	char			*str;

	num = (unsigned int)va_arg(*args, int);
	str = ft_itoa_base(num, "0123456789ABCDEF");
	if (comb->flag == '-')
		ft_xmaj_flag(comb, str, count, num);
	else if (comb->prec == '.')
		ft_xmaj_prec(comb, str, count, num);
	else if (!(comb->flag == '-') || !(comb->prec == '.'))
		ft_xmaj_width(comb, str, count);
	free(str);
}
