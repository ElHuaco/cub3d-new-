/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:03:51 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/21 14:58:45 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t i;

	if (len != 0 && (dest || src))
	{
		if (dest < src)
		{
			i = 0;
			while (i < len)
			{
				*((char *)dest + i) = *((char *)src + i);
				i++;
			}
		}
		else
		{
			i = len;
			while (--i != 0)
				*((char *)dest + i) = *((char *)src + i);
			*((char *)dest) = *((char *)src + i);
		}
	}
	return (dest);
}
