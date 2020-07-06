/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:55:49 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/25 14:56:47 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (*(cdest + i) != *(csrc + i))
			return (*(cdest + i) - *(csrc + i));
		else
			i++;
	}
	return (0);
}
