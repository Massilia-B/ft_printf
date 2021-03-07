/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:20:12 by user42            #+#    #+#             */
/*   Updated: 2020/11/18 18:48:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *list;

	list = *lst;
	if (!del || !lst)
		return ;
	while (list->next)
	{
		ft_lstdelone(list, del);
		list = list->next;
	}
	if (list)
		ft_lstdelone(list, del);
	*lst = NULL;
}
