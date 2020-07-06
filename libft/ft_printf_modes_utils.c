/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modes_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:13:42 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/18 14:38:57 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_firstposflagupdate(char *result, int flag)
{
	char		*temp[2];

	temp[0] = malloc(sizeof(char) * 2);
	temp[0][1] = '\0';
	if (flag == '+')
		temp[0][0] = '+';
	else if (flag == ' ')
		temp[0][0] = ' ';
	else if (flag == '#')
	{
		free(temp[0]);
		temp[0] = malloc(sizeof(char) * 3);
		temp[0][0] = '0';
		temp[0][1] = 'x';
		temp[0][2] = '\0';
	}
	temp[1] = ft_strjoin(temp[0], result);
	free(temp[0]);
	free(result);
	result = temp[1];
	return (result);
}

char		*ft_intprecisionupdate(char *result, int specf, t_format *form)
{
	char		*temp[2];

	if (specf == 'd' || specf == 'i')
	{
		temp[0] = ft_chrstr(form->precision, '0');
		ft_strmv(temp[0], result);
		free(result);
		result = temp[0];
	}
	else if (specf == '-')
	{
		temp[0] = ft_chrstr(form->precision, '0');
		ft_strmv(temp[0], result + 1);
		temp[1] = ft_chrstr(1, '-');
		free(result);
		result = ft_strjoin(temp[1], temp[0]);
		free(temp[1]);
		free(temp[0]);
	}
	return (result);
}

char		*ft_widthupdate(char *result, t_format *form, char s)
{
	char		*temp[2];

	temp[0] = ft_chrstr(form->min_width - ft_strlen(result), ' ');
	if (ft_findflag(form, '-'))
		temp[1] = ft_strjoin(result, temp[0]);
	else
	{
		if (ft_findflag(form, '0'))
		{
			ft_strrep(temp[0], ' ', '0');
			if (((s == 'd') || (s == 'i')) && ((ft_strchr(result, '-')) != 0))
				return (ft_widthnegint(result, temp[0]));
		}
		temp[1] = ft_strjoin(temp[0], result);
	}
	free(result);
	free(temp[0]);
	result = temp[1];
	return (result);
}

char		*ft_widthnegint(char *result, char *temp)
{
	char		*temp2;

	temp2 = ft_strjoin("-", temp);
	free(temp);
	temp = ft_strjoin(temp2, result + 1);
	free(result);
	free(temp2);
	result = temp;
	return (result);
}
