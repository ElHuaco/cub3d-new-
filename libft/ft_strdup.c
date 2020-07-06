/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:45:10 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/18 14:54:32 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	dest = malloc((ft_strlen((char *)src) + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	i = 0;
	while (*((char *)src + i))
	{
		dest[i] = *((char *)src + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
