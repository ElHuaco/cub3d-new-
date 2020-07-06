/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:46:06 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/16 18:55:25 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isspecifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (c);
	else
		return (0);
}

int		ft_isflag(int c)
{
	if (c == '-' || c == '0' || c == '+'
		|| c == '#' || c == ' ' || c == '\'')
		return (c);
	else
		return (0);
}

int		ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_initform(t_format *ptr)
{
	int i;

	i = -1;
	while (++i < FLAG_NUMBER)
		ptr->flags[i] = NONE;
	ptr->min_width = NONE;
	ptr->precision = NONE;
}

void	ft_errorform(t_format *ptr)
{
	int i;

	i = -1;
	while (++i < FLAG_NUMBER)
		ptr->flags[i] = ERROR;
	ptr->min_width = ERROR;
	ptr->precision = ERROR;
}
