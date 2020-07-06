/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:13:41 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/18 14:24:57 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_lastchar(const char *s, int c, int i)
{
	int j;

	j = i + 1;
	while (s[j])
	{
		if (s[j] == c)
			return (0);
		else
			j++;
	}
	return (1);
}

char			*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i])
	{
		if (s[i] == c && ft_lastchar(s, c, i))
		{
			ptr = (char *)s + i;
			return (ptr);
		}
		else
			i++;
	}
	if (c == 0 && s[i] == '\0')
	{
		ptr = (char *)s + i;
		return (ptr);
	}
	return (0);
}
