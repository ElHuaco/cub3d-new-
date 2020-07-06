/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:41:34 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/19 15:53:21 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	temp = *lst;
	while ((*lst)->next)
	{
		del((*lst)->content);
		temp = temp->next;
		free(*lst);
		*lst = temp;
	}
	del((*lst)->content);
	free(*lst);
	*lst = 0;
}
