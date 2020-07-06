/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:05:27 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/18 14:42:06 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_setprecis(const char *l, int i, t_format *form, va_list ptr)
{
	int pre;

	pre = 0;
	if (l[i] == '.')
	{
		if (l[++i] == '*')
		{
			pre = va_arg(ptr, int);
			form->precision = (pre >= 0) ? pre : NONE;
			if ((pre < 0) && !(ft_findflag(form, '-')))
				form->flags[5] = '-';
			++i;
		}
		else
		{
			while (ft_isnum(l[i]))
			{
				pre = pre * 10 + (l[i] - 48);
				i++;
			}
			form->precision = pre;
		}
	}
	return (i);
}

static int	ft_setwidth(const char *l, int i, t_format *form, va_list ptr)
{
	int width;

	width = 0;
	if (l[i] == '*')
	{
		width = va_arg(ptr, int);
		form->min_width = (width >= 0) ? width : -1 * width;
		if ((width < 0) && (!ft_findflag(form, '-')))
			form->flags[5] = '-';
		++i;
	}
	else if (ft_isnum(l[i]))
	{
		while (ft_isnum(l[i]))
		{
			width = width * 10 + (l[i] - 48);
			++i;
		}
		form->min_width = width;
	}
	return (i);
}

int			ft_setformat(const char *line, int i, t_format *form, va_list ptr)
{
	int		j;

	ft_initform(form);
	j = -1;
	while (ft_isflag(line[++i]))
	{
		if (((line[i] == '+') && (ft_findflag(form, '+')))
			|| ((line[i] == '-') && (ft_findflag(form, '-'))))
			continue;
		else
			form->flags[++j] = line[i];
	}
	i = ft_setwidth(line, i, form, ptr);
	i = ft_setprecis(line, i, form, ptr);
	if (!ft_isspecifier(line[i]))
		ft_errorform(form);
	return (i);
}
