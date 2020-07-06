/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:47:17 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/20 10:59:04 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcount(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (*((char *)s + i) == c)
		i++;
	while (*((char *)s + i))
	{
		if (*((char *)s + i) != c && (*((char *)s + i + 1) == c
				|| *((char *)s + i + 1) == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void		ft_set(char **table, char const *s, int str_count, char c)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	while (++i < str_count)
	{
		while (*((char *)s + j) == c && *((char *)s + j))
			j++;
		k = j;
		while (*((char *)s + j) != c && *((char *)s + j))
			j++;
		k = j - k;
		table[i] = malloc(sizeof(char) * (k + 1));
		j = j - k;
		k = 0;
		while (*((char *)s + j) != c && *((char *)s + j))
		{
			table[i][k] = *((char *)s + j);
			j++;
			k++;
		}
		table[i][k] = '\0';
	}
}

char			**ft_split(char const *s, char c)
{
	char	**table;
	int		str_count;

	if (s && s[0])
	{
		str_count = ft_strcount(s, c);
		table = malloc(sizeof(char *) * (str_count + 1));
		if (table == 0)
			return (0);
		ft_set(table, s, str_count, c);
		table[str_count] = 0;
		return (table);
	}
	else
	{
		table = malloc(sizeof(char *) * 1);
		table[0] = 0;
		return (table);
	}
}
