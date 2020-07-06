/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:26:12 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/16 19:13:15 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*j;
	size_t	i;
	size_t	k;
	size_t	lens1;
	size_t	lens2;

	if (s1 && s2)
	{
		lens1 = ft_strlen(s1);
		lens2 = ft_strlen(s2);
		j = malloc(sizeof(char) * (lens1 + lens2 + 1));
		if (j == 0)
			return (0);
		i = -1;
		while (++i < lens1)
			j[i] = *((char *)s1 + i);
		k = -1;
		while (++k < lens2)
			j[i + k] = *((char *)s2 + k);
		j[i + k] = '\0';
		return (j);
	}
	else
		return (0);
}
