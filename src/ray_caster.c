/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:26:32 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/09/03 13:32:10 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cast_till_wall(t_vars *var, int *cell, double *dist)
{
	while (var->map->val[cell[1]][cell[0]] != '1')
	{
		if (dist[2] < dist[3])
		{
			dist[2] += dist[0];
			cell[0] += (int)dist[5];
			var->side = (var->rayx < 0) ? 'w' : 'e';
		}
		else
		{
			dist[3] += dist[1];
			cell[1] += (int)dist[6];
			var->side = (var->rayy < 0) ? 's' : 'n';
		}
	}
}

static void		set_initial_steps(t_vars *v, double *d, int *m)
{
	if (v->rayx < 0)
	{
		d[5] = -1.0;
		d[2] = (v->posx - m[0]) * d[0];
	}
	else
	{
		d[5] = 1.0;
		d[2] = (m[0] + 1.0 - v->posx) * d[0];
	}
	if (v->rayy < 0)
	{
		d[6] = -1.0;
		d[3] = (v->posy - m[1]) * d[1];
	}
	else
	{
		d[6] = 1.0;
		d[3] = (m[1] + 1.0 - v->posy) * d[1];
	}
}

static double	ray_distance(t_vars *var, int col)
{
	double		camera;
	double		dist[7];
	int			map_cell[2];

	camera = 2 * col / (double)var->map->res_width - 1;
	var->rayx = var->dirx + var->planex * camera;
	var->rayy = var->diry + var->planey * camera;
	map_cell[0] = (int)var->posx;
	map_cell[1] = (int)var->posy;
	dist[0] = fabs(1 / var->rayx);
	dist[1] = fabs(1 / var->rayy);
	set_initial_steps(var, dist, map_cell);
	cast_till_wall(var, map_cell, dist);
	if ((var->side == 'w') || (var->side == 'e'))
	{
		dist[4] = (map_cell[0] - var->posx + (1 - dist[5]) / 2) / var->rayx;
		var->ray_hit[col] = var->posy + dist[4] * var->rayy;
	}
	else
	{
		dist[4] = (map_cell[1] - var->posy + (1 - dist[6]) / 2) / var->rayy;
		var->ray_hit[col] = var->posx + dist[4] * var->rayx;
	}
	var->ray_hit[col] -= floor(var->ray_hit[col]);
	return (dist[4]);
}

static void		malloc_or_free_caster_param(t_vars *var, char *str)
{
	if (!(ft_strcmp(str, "malloc")))
	{
		var->ray_hit = malloc(sizeof(double) * var->map->res_width);
		var->map->wall_lineheight = malloc(sizeof(int) * var->map->res_width);
		var->map->wall_start = malloc(sizeof(int) * var->map->res_width);
		var->ray_distance = malloc(sizeof(double) * var->map->res_width);
	}
	else if (!(ft_strcmp(str, "free")))
	{
		free(var->ray_hit);
		free(var->map->wall_start);
		free(var->map->wall_lineheight);
		free(var->ray_distance);
	}
	else
		error_exit("BAD CODE\n");
}

int				ray_caster(t_vars *var)
{
	int		i;
	int		j;
	double	len[3];

	malloc_or_free_caster_param(var, "malloc");
	camera_update(var);
	i = -1;
	while (++i < var->map->res_width)
	{
		len[0] = ray_distance(var, i);
		var->ray_distance[i] = len[0];
		set_pixel_limits(var, len, i);
		j = -1;
		while (++j < (int)len[2])
			put_pixel_ceilflo(var->img, i, j, var->map->ceil_col);
		while (j < (int)len[1])
			put_pixel_wall_texture(var->img, i, j++, var);
		while (j < var->map->res_height - 1)
			put_pixel_ceilflo(var->img, i, j++, var->map->floor_col);
	}
	sprite_caster_and_frame_to_win(var, var->img);
	malloc_or_free_caster_param(var, "free");
	free(var->map->sprites);
	return (0);
}
