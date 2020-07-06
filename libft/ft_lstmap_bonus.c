/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:00:15 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/20 13:01:35 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlst;
	t_list *first;

	if (lst && f != 0 && del != 0)
	{
		newlst = malloc(sizeof(t_list) * 1);
		if (newlst == 0)
			return (0);
		first = newlst;
		while (lst->next)
		{
			newlst->content = f(lst->content);
			newlst->next = malloc(sizeof(t_list) * 1);
			if (newlst->next == 0)
				return (0);
			lst = lst->next;
			newlst = newlst->next;
		}
		newlst->content = f(lst->content);
		newlst->next = 0;
		return (first);
	}
	else
		return (0);
}
