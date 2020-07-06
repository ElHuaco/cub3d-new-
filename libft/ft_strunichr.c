/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunichr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:30:20 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/18 15:30:48 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strunichr(int len, int c)
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
