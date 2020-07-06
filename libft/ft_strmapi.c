/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:49:57 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/20 10:16:11 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;
	int		i;

	if (s && f)
	{
		len = ft_strlen((char *)s);
		str = malloc(sizeof(char) * (len + 1));
		if (str == 0)
			return (0);
		i = -1;
		while (++i < len)
			str[i] = f(i, *((char *)s + i));
		str[i] = '\0';
		return (str);
	}
	else
		return (0);
}
