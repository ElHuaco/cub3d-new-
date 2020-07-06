/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:00:50 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/25 14:59:15 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int i;

	i = 0;
	while (*((char *)set + i))
	{
		if (c == *((char *)set + i))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_find_start(char const *s1, char const *set)
{
	int i;
	int l;

	l = ft_strlen((char *)s1) - 1;
	i = 0;
	while (ft_isset(*((char *)s1 + i), set) && i < l)
		i++;
	return (i);
}

static int	ft_find_end(char const *s1, char const *set)
{
	int i;

	i = ft_strlen((char *)s1) - 1;
	while (ft_isset(*((char *)s1 + i), set) && i > 0)
		i--;
	return (i);
}

static void	ft_setresult(char *result, int s, int len, char const *s1)
{
	int i;

	i = -1;
	while (++i < len)
		result[i] = *((char *)s1 + s + i);
	result[i] = '\0';
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		s;
	int		e;

	if (s1 && set)
	{
		s = ft_find_start(s1, set);
		e = ft_find_end(s1, set);
		if (ft_strlen((char *)s1) != 0
				&& s == ((int)ft_strlen((char *)s1) - 1) && e == 0)
		{
			result = malloc(sizeof(char) * 1);
			result[0] = '\0';
		}
		else
		{
			result = malloc(sizeof(char) * (e - s + 2));
			if (result == 0)
				return (0);
			ft_setresult(result, s, e - s + 1, s1);
		}
		return (result);
	}
	else
		return (0);
}
