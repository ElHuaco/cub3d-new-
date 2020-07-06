/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:32:58 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/18 15:33:13 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
