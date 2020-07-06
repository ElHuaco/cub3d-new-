/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:50:24 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/21 12:31:31 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *s)
{
	int					i;
	int					sign;
	unsigned long long	num;
	char				*str;

	str = (char *)s;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - 48) + (num * 10);
		i++;
	}
	return (sign * num);
}
