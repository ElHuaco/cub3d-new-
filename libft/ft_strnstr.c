/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:43:21 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/21 15:13:59 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s, const char *f, size_t n)
{
	size_t	i;
	size_t	j;
	char	*to_find;

	if (*((char *)f))
	{
		to_find = (char *)f;
		i = 0;
		while (*((char *)s + i) && i < n)
		{
			j = 0;
			if (*((char *)s + i) == to_find[j])
			{
				while (to_find[j] && *((char *)s + i + j) == to_find[j]
						&& i + j < n)
					j++;
				if (j == (size_t)ft_strlen(to_find))
					return ((char *)s + i);
			}
			i++;
		}
		return (0);
	}
	else
		return ((char *)s);
}
