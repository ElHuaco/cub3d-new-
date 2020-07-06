/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:04:41 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/18 14:48:48 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkform(char specf, t_format *form, va_list ptr)
{
	int		i[2];

	i[1] = 0;
	if (!ft_finderror(form))
	{
		if (specf == 'd' || specf == 'i')
			i[1] = va_arg(ptr, int);
		i[0] = -1;
		while (++i[0] < FLAG_NUMBER)
		{
			if ((form->flags[i[0]] == '+') && !(ft_issignedvalid(specf, i[1])))
				form->flags[i[0]] = NONE;
			else if ((form->flags[i[0]] == ' ') && ((ft_findflag(form, '+'))
					|| !(ft_issignedvalid(specf, i[1]))))
				form->flags[i[0]] = NONE;
			else if ((form->flags[i[0]] == '#') && !(ft_issharpvalid(specf)))
				form->flags[i[0]] = NONE;
			else if ((form->flags[i[0]] == '0') && ((form->precision != NONE)
				|| (ft_findflag(form, '-'))))
				form->flags[i[0]] = NONE;
			else if ((form->flags[i[0]] == '\'') && !(ft_isprimavalid(specf)))
				form->flags[i[0]] = NONE;
		}
	}
	return (i[1]);
}

static void	ft_checkerror(char sp, t_format *form)
{
	int		i;

	if (!ft_finderror(form))
	{
		i = -1;
		while (++i < FLAG_NUMBER)
		{
			if ((form->flags[i] == '+') && !((sp == 'd') || (sp = 'i')))
				form->flags[i] = ERROR;
			else if ((form->flags[i] == ' ') && !((sp == 'd') || (sp == 'i')))
				form->flags[i] = ERROR;
			else if ((form->flags[i] == '#') && !((sp == 'x') || (sp == 'X')))
				form->flags[i] = ERROR;
			else if ((form->flags[i] == '0') && ((sp == 's') || (sp == 'c')
				|| (sp == 'p')))
				form->flags[i] = ERROR;
		}
		if ((form->precision != NONE) && ((sp == 'c')))
			form->precision = ERROR;
	}
}

static int	ft_printmode(char specifier, t_format *form, int arg, va_list ptr)
{
	if (specifier == '%')
		return (ft_printf_chr(form, specifier, 37));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_printf_int(form, specifier, arg));
	else if (specifier == 'c')
		return (ft_printf_chr(form, specifier, va_arg(ptr, unsigned int)));
	else if (specifier == 'u' || specifier == 'x' || specifier == 'X')
		return (ft_printf_unsign(form, specifier, va_arg(ptr, unsigned int)));
	else if (specifier == 's')
		return (ft_printf_str(form, specifier, va_arg(ptr, char *)));
	else if (specifier == 'p')
		return (ft_printf_mem(form, specifier, va_arg(ptr, void *)));
	else
		return (0);
}

int			ft_printf(const char *line, ...)
{
	va_list		ptr;
	int			i[3];
	t_format	*form;

	i[2] = 0;
	i[0] = -1;
	va_start(ptr, line);
	while (line[++i[0]])
	{
		if (line[i[0]] == '%')
		{
			form = malloc(sizeof(t_format) * 1);
			i[0] = ft_setformat(line, i[0], form, ptr);
			i[1] = ft_checkform(line[i[0]], form, ptr);
			ft_checkerror(line[i[0]], form);
			i[2] += ft_printmode(line[i[0]], form, i[1], ptr);
			free(form);
			continue;
		}
		else
			write(1, line + i[0], 1);
		i[2]++;
	}
	va_end(ptr);
	return (i[2]);
}
