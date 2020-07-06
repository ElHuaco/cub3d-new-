/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 09:27:36 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/18 14:46:18 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*dest;

	if (str)
	{
		dest = malloc(sizeof(char) * (n + 1));
		if (dest == 0)
			return (0);
		i = -1;
		while (str[++i] && i < n)
			dest[i] = str[i];
		dest[i] = '\0';
		return (dest);
	}
	else
		return (0);
}

char	*ft_chrstr(int len, int c)
{
	int		i;
	char	*result;

	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	i = -1;
	while (++i < len)
		result[i] = c;
	return (result);
}

void	ft_strmv(char *into, char *from)
{
	int		len1;
	int		len2;
	int		i;

	if (into && from)
	{
		len1 = ft_strlen(into);
		len2 = ft_strlen(from);
		i = -1;
		while (++i < len2)
			into[len1 - len2 + i] = from[i];
	}
}

void	ft_strrep(char *str, int changed, int replacer)
{
	int		i;

	if (str)
	{
		i = -1;
		while (str[++i])
		{
			if (str[i] == changed)
				str[i] = replacer;
		}
	}
}
