/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:23:49 by masboula          #+#    #+#             */
/*   Updated: 2020/12/23 15:01:15 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_conv(t_format *comb, va_list *args, int *count)
{
	char		c;
	int			i;
	const char	*convert_to = "scdiupxX%";
	static void	(*get_tab[9])();

	get_tab[0] = &type_str;
	get_tab[1] = &type_c;
	get_tab[2] = &type_id;
	get_tab[3] = &type_id;
	get_tab[4] = &type_u;
	get_tab[5] = &type_p;
	get_tab[6] = &type_x;
	get_tab[7] = &type_xmaj;
	get_tab[8] = &type_mod;
	c = comb->spec;
	i = 0;
	while (convert_to[i])
	{
		if (c == convert_to[i])
			(*get_tab[i])(comb, args, count);
		i++;
	}
}
