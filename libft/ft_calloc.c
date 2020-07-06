/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:27:24 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/21 14:55:51 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*buff;
	size_t			i;

	buff = malloc(size * count);
	if (buff == 0)
		return (0);
	i = 0;
	while (i < size * count)
	{
		*((char *)buff + i) = '\0';
		i++;
	}
	return (buff);
}
