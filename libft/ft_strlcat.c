/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:40:42 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/25 14:57:46 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_strnlen(char *str, size_t n)
{
	size_t i;

	i = 0;
	while (str[i] && i < n)
		i++;
	return (i);
}

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strnlen(dest, size);
	srclen = ft_strlen(src);
	if (destlen == size)
		return (size + srclen);
	if (size - destlen > srclen)
		ft_memcpy(dest + destlen, src, srclen + 1);
	else
	{
		ft_memcpy(dest + destlen, src, size - destlen - 1);
		dest[size - 1] = '\0';
	}
	return (destlen + srclen);
}
