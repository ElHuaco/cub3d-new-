/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:26:32 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/09 20:18:09 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cast_till_wall(t_vars *var, int *cell, double *dist)
{
	while (var->map->val[cell[1]][cell[0]] != '1')
	{
		if (dist[2] < dist[3])
		{
			dist[2] += dist[0];
			cell[0] += (int)dist[5];
			var->side = (var->rayX < 0) ? 'w' : 'e';
		}
		else
		{
			dist[3] += dist[1];
			cell[1] += (int)dist[6];
			var->side = (var->rayY < 0) ? 's' : 'n';
		}
	}
}

static void	set_initial_steps(t_vars *v, double *d, int *m)
{
	if (v->rayX < 0)
	{
		d[5] = -1.0;
		d[2] = (v->posX - m[0]) * d[0];
	}
	else
	{
		d[5] = 1.0;
		d[2] = (m[0] + 1.0 - v->posX) * d[0];
	}
	if (v->rayY < 0)
	{
		d[6] = -1.0;
		d[3] = (v->posY - m[1]) * d[1];
	}
	else
	{
		d[6] = 1.0;
		d[3] = (m[1] + 1.0 - v->posY) * d[1];
	}
}

static double	ray_distance(t_vars *var, int col)
{
	double		camera;
	double		dist[7];
	int			map_cell[2];

	camera = 2 * col / (double)var->map->res_width - 1;
	var->rayX = var->dirX + var->planeX * camera;
	var->rayY = var->dirY + var->planeY * camera;
	map_cell[0] = (int)var->posX;
	map_cell[1] = (int)var->posY;
	dist[0] = fabs(1 / var->rayX);
	dist[1] = fabs(1 / var->rayY);
	set_initial_steps(var, dist, map_cell);
	cast_till_wall(var, map_cell, dist);
	if ((var->side == 'w') || (var->side == 'e'))
	{
		dist[4] = (map_cell[0] - var->posX + (1 - dist[5]) / 2) / var->rayX;
		var->ray_hit[col] = var->posY + dist[4] * var->rayY;
	}
	else
	{
		dist[4] = (map_cell[1] - var->posY + (1 - dist[6]) / 2) / var->rayY;
		var->ray_hit[col] = var->posX + dist[4] * var->rayX;
	}
	var->ray_hit[col] -= floor(var->ray_hit[col]);
	return (dist[4]);
}

static void	malloc_or_free_caster_params(t_vars *var, t_imgs *img, char *str)
{
	int i;

	if (!(ft_strcmp(str, "malloc")))
	{
		var->ray_hit = malloc(sizeof(double) * var->map->res_width);
		var->map->wall_lineheight = malloc(sizeof(int) * var->map->res_width);
		var->map->wall_start = malloc(sizeof(int) * var->map->res_width);
		var->ray_distance = malloc(sizeof(double) * var->map->res_width);
	}
	else if (!(ft_strcmp(str, "free")))
	{
		i = -1;
		while (++i < 6)
			mlx_destroy_image(var->win, img[i].img);
		free(var->ray_hit);
		free(var->map->wall_start);
		free(var->map->wall_lineheight);
		free(var->ray_distance);
	}
	else
		error_exit("BAD CODE\n");
}

int		ray_caster(t_vars *var)
{
	int		i;
	int		j;
	double	len[3];
	t_imgs	img[6];

	set_mlx_texture_imgs(var, img);
	malloc_or_free_caster_params(var, img, "malloc");
	camera_update(var);
	i = -1;
	while (++i < var->map->res_width)
	{
		len[0] = ray_distance(var, i);
		var->ray_distance[i] = len[0];
		set_pixel_limits(var, len, i);
		j = -1;
		while (++j < (int)len[2])
			put_pixel_ceilflo(img, i, j, var->map->ceiling_color);
		while (j < (int)len[1])
			put_pixel_wall_texture(img, i, j++, var);
		while (j < var->map->res_height - 1)
			put_pixel_ceilflo(img, i, j++, var->map->floor_color);
	}
	sprite_caster_and_frame_to_win(var, img);
	malloc_or_free_caster_params(var, img, "free");
	return (0);
}
