/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:28:46 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:09:19 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_conv(char *format, t_format *comb)
{
	const char	*conv = "scdiupxX%";
	int			i;

	i = 0;
	while (conv[i])
	{
		if (*format == conv[i])
		{
			comb->spec = conv[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_get_prec(char *format, t_format *comb)
{
	if (*format == '.')
	{
		comb->prec = '.';
		return (1);
	}
	return (0);
}

int	ft_get_zero(char *format, t_format *comb)
{
	if (*format == '0')
	{
		comb->zero = 0;
		return (1);
	}
	return (0);
}

int	ft_get_sign(char *format, t_format *comb)
{
	if (*format == '-')
	{
		comb->flag = '-';
		return (1);
	}
	return (0);
}
