/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:06:56 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/16 18:55:07 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_issignedvalid(int c, int arg)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'u' || c == 'x' || c == 'X')
		return (0);
	if ((c == 'd' || c == 'i') && (arg < 0))
		return (0);
	else
		return (1);
}

int		ft_issharpvalid(int c)
{
	if (c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

int		ft_isprimavalid(int c)
{
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	else
		return (0);
}

int		ft_findflag(t_format *form, int flag)
{
	int		i;

	i = -1;
	while (++i < FLAG_NUMBER)
	{
		if (form->flags[i] == flag)
			return (1);
	}
	return (0);
}

int		ft_finderror(t_format *form)
{
	int		i;

	i = -1;
	while (++i < FLAG_NUMBER)
	{
		if (form->flags[i] == ERROR)
			return (1);
	}
	if (form->min_width == ERROR)
		return (1);
	if (form->precision == ERROR)
		return (1);
	return (0);
}
