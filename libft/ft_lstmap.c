/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:27:02 by user42            #+#    #+#             */
/*   Updated: 2020/11/19 13:05:18 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	void	*content;

	if (lst == NULL || f == NULL)
		return (NULL);
	content = f(lst->content);
	if (content == 0)
		newlst = ft_lstmap(lst->next, f, del);
	else
	{
		newlst = ft_lstnew(content);
		if (newlst == 0)
			newlst = ft_lstmap(lst->next, f, del);
		newlst->next = ft_lstmap(lst->next, f, del);
	}
	return (newlst);
}
