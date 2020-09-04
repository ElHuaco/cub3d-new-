/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 10:45:07 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/09/04 09:09:31 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			set_initial_camera_pos(t_vars *var, t_maps *map, int i, int j)
{
	char c;

	c = map->val[i][j];
	if ((c == 'W') || (c == 'E') || (c == 'N') || (c == 'S')
		|| (c == 'N'))
	{
		var->diry = -1 * (c == 'N') + 1 * (c == 'S');
		var->dirx = -1 * (c == 'W') + 1 * (c == 'E');
		var->posx = j + 0.5;
		var->posy = i + 0.5;
		var->planey = 0.66 * (c == 'E') - 0.66 * (c == 'W')
			+ 0.0 * ((c == 'N') || (c == 'S'));
		var->planex = -0.66 * (c == 'S') + 0.66 * (c == 'N')
			+ 0.0 * ((c == 'W') || (c == 'E'));
		map->val[i][j] = '0';
		var->rot = 0;
		var->pmove = 0;
		var->lmove = 0;
		return (1);
	}
	else
		return (0);
}

int			set_floor_ceil_color(t_maps *map, char *buff, int i)
{
	int		ceil_or_floor;
	int		color[3];

	ceil_or_floor = (buff[i] == 'F') ? 0 : 1;
	while (buff[++i] == ' ')
		;
	color[0] = ft_atoi(buff + i);
	i += digit_number(color[0], 10) + 1;
	color[1] = ft_atoi(buff + i);
	i += digit_number(color[1], 10) + 1;
	color[2] = ft_atoi(buff + i);
	if ((color[0] < 0) || (color[1] < 0) || (color[2] < 0)
		|| (color[0] > 255) || (color[1] > 255) || (color[2] > 255))
		error_exit(EINFOC);
	if (!ceil_or_floor)
	{
		map->floor_col = color[0] * 65536 + color[1] * 256 + color[2];
		map->is_floor_color_set = 1;
	}
	else
	{
		map->ceil_col = color[0] * 65536 + color[1] * 256 + color[2];
		map->is_ceil_color_set = 1;
	}
	return (i + digit_number(color[2], 10));
}

int			set_window_resolution(t_maps *map, char *buff, int i)
{
	int		j;

	while (buff[++i] == ' ')
		;
	j = -1;
	while (ft_isdigit(buff[i + ++j]))
		;
	map->res_width = ft_atoi(buff + i);
	i += j - 1;
	while (buff[++i] == ' ')
		;
	j = -1;
	while (ft_isdigit(buff[i + ++j]))
		;
	map->res_height = ft_atoi(buff + i);
	if ((map->res_width <= 0) || (map->res_height <= 0)
		|| ((map->res_width == 1) && (map->res_height == 1)))
		error_exit(EINFOR);
	map->res_width = (map->res_width > 2575) ? 2575 : map->res_width;
	map->res_height = (map->res_height > 1440) ? 1440 : map->res_height;
	return (i + j);
}

int			set_texture_paths(t_maps *map, char *buff, int i)
{
	int		j;
	int		k;

	j = i;
	i++;
	while (buff[++i] == ' ')
		;
	k = i;
	while (buff[i++] != '\n')
		;
	buff[i - 1] = 0;
	if ((buff[j] == 'N') && (buff[j + 1] == 'O') && !(map->side[0]))
		map->side[0] = ft_strdup(buff + k);
	else if ((buff[j] == 'S') && (buff[j + 1] == 'O') && !(map->side[1]))
		map->side[1] = ft_strdup(buff + k);
	else if ((buff[j] == 'W') && (buff[j + 1] == 'E') && !(map->side[2]))
		map->side[2] = ft_strdup(buff + k);
	else if ((buff[j] == 'E') && (buff[j + 1] == 'A') && !(map->side[3]))
		map->side[3] = ft_strdup(buff + k);
	else if ((buff[j] == 'S') && (buff[j + 1] != 'O') && !(map->side[4]))
		map->side[4] = ft_strdup(buff + k);
	/*else
		error_exit(EINFOT)*/;
	return (i);
}

void		set_image_textures(t_vars *var)
{
	int		i;

	var->img = malloc(sizeof(t_imgs) * 6);
	var->img[0].img = mlx_new_image(var->mlx, var->map->res_width,
		var->map->res_height);
	i = 0;
	while (++i < 6)
		var->img[i].img = mlx_xpm_file_to_image(var->mlx,
			var->map->side[i - 1], &(var->img[i].img_w),
			&(var->img[i].img_h));
	i = -1;
	while (++i < 6)
	{
		if (var->img[i].img)
			var->img[i].addr = mlx_get_data_addr(var->img[i].img,
				&(var->img[i].bpp), &(var->img[i].ll),
				&(var->img[i].endian));
		else
			error_exit(ETEXPATH);
	}
}
