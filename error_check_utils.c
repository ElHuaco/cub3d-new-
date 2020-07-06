/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 10:45:44 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/06 12:35:02 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			is_cub_file_chr(int c)
{
	if ((c == 'W') || (c == 'E') || (c == 'N') || (c == 'S')
		|| (c == 'N') || (c == '0') || (c == '1') || (c == '2')
		|| (c == ' '))
		return (1);
	else
		return (0);
}

char		**map_to_rectangle_by_sp(char **val)
{
	int		max_len;
	int		i;
	char	*temp[2];

	max_len = ft_strlen(val[0]);
	i = 0;
	while (val[++i])
	{
		if ((int)ft_strlen(val[i]) > max_len)
			max_len = ft_strlen(val[i]);
	}
	i = -1;
	while (val[++i])
	{
		if ((int)ft_strlen(val[i]) < max_len)
		{
			temp[0] = ft_strunichr(-1 * ft_strlen(val[i]) + max_len, ' ');
			temp[1] = ft_strjoin(val[i], temp[0]);
			free(temp[0]);
			free(val[i]);
			val[i] = temp[1];
		}
	}
	return (val);
}

int			is_map_values_topoerr(char **val, int i, int j, int arr_size)
{
	int			len;
	int			k;
	int			l;

	len = ft_strlen(val[i]) - 1;
	k = -1;
	while (val[i][++k] == ' ')
	{
	}
	l = len + 1;
	while (val[i][--l] == ' ')
	{
	}
	if ((val[i][k] != '1') || (val[i][l] != '1'))
		return (1);
	else if ((!i || (i == arr_size))
		&& ((val[i][j] != '1') && (val[i][j] != ' ')))
		return (1);
	else if ((((i != 0) && (val[i - 1][j] == ' '))
		|| (((i != 0) && (j != 0)) && (val[i - 1][j - 1] == ' '))
		|| (((i != 0) && (j != len)) && (val[i - 1][j + 1] == ' '))
		|| ((j != 0) && (val[i][j - 1] == ' '))
		|| ((j != len) && (val[i][j + 1] == ' '))
		|| ((i != arr_size) && (val[i + 1][j] == ' '))
		|| (((i != arr_size) && (j != len)) && (val[i + 1][j + 1] == ' '))
		|| (((i != arr_size) && (j != 0)) && (val[i + 1][j - 1] == ' ')))
		&& ((val[i][j] != '1') && (val[i][j] != ' ')))
		return (1);
	else
		return (0);
}
