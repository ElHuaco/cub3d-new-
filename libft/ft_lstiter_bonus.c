/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:57:02 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/20 10:52:07 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f != 0 && lst != 0)
	{
		while (lst->next)
		{
			f(lst->content);
			lst = lst->next;
		}
		f(lst->content);
	}
}
