/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set_params_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 10:45:07 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/09 12:24:49 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int			set_initial_camera_pos(t_vars *var, t_maps *map, int i, int j)
{
	char	c;

	c = map->val[i][j];
	if ((c == 'W') || (c == 'E') || (c == 'N') || (c == 'S')
		|| (c == 'N'))
	{
		var->dirX = -1 * (c == 'N') + 1 * (c == 'S');
		var->dirY = -1 * (c == 'W') + 1 * (c == 'E');
		var->posX = j + 0.5;
		var->posY = i + 0.5;
		var->planeX = 0.66 * (c == 'E') - 0.66 * (c == 'W')
			+ 0.0 * ((c == 'N') || (c == 'S'));
		var->planeY = 0.66 * (c == 'N') - 0.66 * (c == 'S')
			+ 0.0 * ((c == 'W') || (c == 'E'));
		map->val[i][j] = '0';
		var->rot = 0;
		var->Pmove = 0;
		var->Lmove = 0;
		return (1);
	}
	else
		return (0);
}

int			set_floor_ceil_color(t_maps *map, char *buff, int i)
{
	int		j;
	int		ceil_or_floor;
	int		r;
	int		g;
	int		b;

	ceil_or_floor = (buff[i] == 'F') ? 0 : 1;
	while (buff[++i] == ' ')
	{
	}
	r = ft_atoi(buff + i) * 65536;
	j = -1;
	while (ft_isdigit(buff[i + ++j]))
	{
	}
	i += j + 1;
	g = ft_atoi(buff + i) * 256;
	j = -1;
	while (ft_isdigit(buff[i + ++j]))
	{
	}
	i += j + 1;
	b = ft_atoi(buff + i);
	if ((r < 0) || (g < 0) || (b < 0))
		error_exit(EINFO);
	if (!ceil_or_floor)
		map->floor_color = r + g + b;
	else
		map->ceiling_color = r + g + b;
	return (i + digit_number(b, 10));
}

int			set_window_resolution(t_maps *map, char *buff, int i)
{
	int		j;

	while (buff[++i] == ' ')
	{
	}
	j = -1;
	while (ft_isdigit(buff[i + ++j]))
	{
	}
	map->res_width = ft_atoi(buff + i);
	i += j - 1;
	while (buff[++i] == ' ')
	{
	}
	j = -1;
	while (ft_isdigit(buff[i + ++j]))
	{
	}
	map->res_height = ft_atoi(buff + i);
	if ((map->res_width <= 0) || (map->res_height <= 0))
		error_exit(EINFO);
	map->res_width *= (map->res_width > 2575) ? 2575 / map->res_width : 1;
	map->res_height *= (map->res_height > 1440) ? 1440 / map->res_height : 1;
	return (i + j);
}

int			set_texture_paths(t_maps *map, char *buff, int i)
{
	int		j;
	int		k;

	j = i;
	i++;
	while (buff[++i] == ' ')
	{
	}
	k = i;
	if ((buff[i] != '.') || (buff[i + 1] != '/'))
		error_exit(EINFO);
	while (buff[i++] != '\n')
	{
	}
	buff[i - 1] = 0;
	if (buff[j] == 'N')
		map->north = ft_strdup(buff + k);
	else if ((buff[j] == 'S') && (buff[j + 1] == 'O'))
		map->south = ft_strdup(buff + k);
	else if (buff[j] == 'W')
		map->west = ft_strdup(buff + k);
	else if (buff[j] == 'E')
		map->east = ft_strdup(buff + k);
	else
		map->sprite = ft_strdup(buff + k);
	return (i);
}

void		set_mlx_texture_imgs(t_vars *var, t_imgs *img)
{
	int		i;

	img[0].img = mlx_new_image(var->mlx, var->map->res_width,
		var->map->res_height);
	img[1].img = mlx_xpm_file_to_image(var->mlx, var->map->north,
		&img[1].img_w, &img[1].img_h);
	img[2].img = mlx_xpm_file_to_image(var->mlx, var->map->south,
		&img[2].img_w, &img[2].img_h);
	img[3].img = mlx_xpm_file_to_image(var->mlx, var->map->west,
		&img[3].img_w, &img[3].img_h);
	img[4].img = mlx_xpm_file_to_image(var->mlx, var->map->east,
		&img[4].img_w, &img[4].img_h);
	img[5].img = mlx_xpm_file_to_image(var->mlx, var->map->sprite,
		&img[5].img_w, &img[5].img_h);
	i = -1;
	while (++i < 6)
	{
		if (img[i].img)
			img[i].addr = mlx_get_data_addr(img[i].img, &img[i].bpp,
				&img[i].ll, &img[i].endian);
		else
			error_exit(ETEXPATH);
	}
}
