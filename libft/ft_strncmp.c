/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:24:51 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/21 14:48:50 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (cs1[i] == cs2[i])
			i++;
		else
		{
			if (cs1[i] > cs2[i])
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}
