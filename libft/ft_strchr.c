/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:36:12 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/18 14:35:07 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
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
