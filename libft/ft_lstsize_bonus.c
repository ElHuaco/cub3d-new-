/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:38:54 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/19 13:08:56 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int	size;

	if (lst == 0)
		return (0);
	size = 1;
	while (lst->next)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
