/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:30:53 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/18 15:31:09 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
