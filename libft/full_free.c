/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 10:37:58 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/06 10:40:17 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		full_free(void **buff, int arr_len)
{
	int i;

	if (buff)
	{
		i = -1;
		while (++i < arr_len && buff[i])
		{
			if (buff[i])
				free(buff[i]);
		}
		free(buff);
	}
}
