/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:57:12 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/18 12:46:10 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_int(t_format *f, char specf, int arg)
{
	char	*result;
	int		len;
	char	*sign;

	if (!ft_finderror(f))
	{
		result = ft_itoabase(arg, "0123456789");
		if ((f->precision == 0) && (arg == 0))
			result = ft_chrstr(0, 0);
		if ((f->precision != NONE) && (((int)ft_strlen(result) - 1
			* ((sign = ft_strchr(result, '-')) != 0)) < f->precision))
			result = ft_intprecisionupdate(result, 'd' * (!sign)
				+ '-' * ((sign) != 0), f);
		if ((ft_findflag(f, '+')))
			result = ft_firstposflagupdate(result, '+');
		if ((ft_findflag(f, ' ')))
			result = ft_firstposflagupdate(result, ' ');
		if ((f->min_width != NONE) && ((int)ft_strlen(result) < f->min_width))
			result = ft_widthupdate(result, f, specf);
		len = ft_strlen(result);
		write(1, result, len);
		free(result);
		return (len);
	}
	return (0);
}

int			ft_printf_chr(t_format *f, char specf, unsigned int arg)
{
	char	*result;
	int		len;

	if (!ft_finderror(f))
	{
		result = malloc(sizeof(char) * 2);
		result[1] = '\0';
		if (arg)
			result[0] = arg;
		else
			result[0] = '*';
		if ((f->min_width != NONE) && (1 < f->min_width))
			result = ft_widthupdate(result, f, specf);
		len = ft_strlen(result);
		if (!arg)
			ft_strrep(result, '*', 0);
		write(1, result, len);
		free(result);
		return (len);
	}
	return (0);
}

int			ft_printf_unsign(t_format *f, char specf, unsigned int arg)
{
	char	*result;
	int		len;

	if (!ft_finderror(f))
	{
		result = ft_ultoamode(arg, specf);
		if ((f->precision == 0) && (arg == 0))
			result = ft_chrstr(0, 0);
		if ((f->precision != NONE) && ((int)ft_strlen(result) < f->precision))
			result = ft_intprecisionupdate(result, 'd', f);
		if ((ft_findflag(f, '#')) && (specf != 'u'))
			result = ft_firstposflagupdate(result, '#');
		if ((ft_findflag(f, '+')))
			result = ft_firstposflagupdate(result, '+');
		if ((ft_findflag(f, ' ')))
			result = ft_firstposflagupdate(result, ' ');
		if ((f->min_width != NONE) && ((int)ft_strlen(result) < f->min_width))
			result = ft_widthupdate(result, f, specf);
		len = ft_strlen(result);
		write(1, result, len);
		free(result);
		return (len);
	}
	return (0);
}

int			ft_printf_str(t_format *f, char specf, char *arg)
{
	char	*result;
	int		len;

	if (!ft_finderror(f))
	{
		if (!arg)
			result = ft_strdup("(null)");
		else
			result = ft_strdup(arg);
		if ((f->precision != NONE) && ((int)ft_strlen(result) > f->precision))
			result = ft_strndup(result, f->precision);
		if ((ft_findflag(f, '+')))
			result = ft_firstposflagupdate(result, '+');
		if ((ft_findflag(f, ' ')))
			result = ft_firstposflagupdate(result, ' ');
		if ((f->min_width != NONE) && ((int)ft_strlen(result) < f->min_width))
			result = ft_widthupdate(result, f, specf);
		len = ft_strlen(result);
		write(1, result, len);
		free(result);
		return (len);
	}
	return (0);
}

int			ft_printf_mem(t_format *f, char specf, void *arg)
{
	char	*result;
	char	*temp[2];
	int		len;

	if (!ft_finderror(f))
	{
		if (!arg)
			result = ft_strdup("0");
		else
			result = ft_ultoabase((unsigned long)arg, "0123456789abcdef");
		temp[0] = ft_strdup("0x");
		temp[1] = ft_strjoin(temp[0], result);
		free(temp[0]);
		free(result);
		result = temp[1];
		if ((f->precision != NONE) && ((int)ft_strlen(result) > f->precision))
			result = ft_strndup(result, f->precision + 2);
		if ((f->min_width != NONE) && ((int)ft_strlen(result) < f->min_width))
			result = ft_widthupdate(result, f, specf);
		len = ft_strlen(result);
		write(1, result, len);
		free(result);
		return (len);
	}
	return (0);
}
