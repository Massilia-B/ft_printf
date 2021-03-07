/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_convert2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:43:29 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:08:58 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_str(t_format *comb, va_list *args, int *count)
{
	char	*str;
	int		s;

	s = 0;
	str = va_arg(*args, char*);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		s = 1;
	}
	if (comb->flag == '-')
		ft_str_flag(comb, str, count);
	else if (comb->prec == '.')
		ft_str_prec(comb, str, count, s);
	else if (!(comb->flag == '-') && !(comb->prec == '.'))
		ft_str_width(comb, str, count);
	if (s == 1)
		free(str);
}

void	type_c(t_format *comb, va_list *args, int *count)
{
	if (comb->flag == '-')
		ft_char_flag(comb, args, count);
	else if (comb->prec == '.')
		ft_char_prec(comb, args, count);
	else if (!(comb->prec == '.') && !(comb->flag == '-'))
		ft_char_width(comb, args, count);
}

void	type_p(t_format *comb, va_list *args, int *count)
{
	void			*ptr;
	unsigned long	add;

	ptr = va_arg(*args, void *);
	add = (unsigned long)ptr;
	if (comb->flag == '-')
		ft_p_flag(comb, add, count);
	if (comb->prec == '.')
		ft_p_prec(comb, add, count);
	else if (!(comb->flag == '-') && !(comb->prec == '.'))
		ft_p_width(comb, add, count);
}

void	type_mod(t_format *comb, va_list *args, int *count)
{
	(void)args;
	if (comb->flag == '-')
		ft_mod_flag(comb, count);
	else if (comb->prec == '.')
		ft_mod_prec(comb, count);
	else if (!(comb->prec == '.') && !(comb->flag == '-'))
		ft_mod_width(comb, count);
}
