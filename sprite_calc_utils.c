/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calc_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:13:34 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/13 13:27:54 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_sprite_limits(t_vars *var, int *len, double *proyect)
{
	double		scaling;

	scaling = fabs(var->map->res_height / proyect[1]);
	len[2] = (int)(0.5 * (var->map->res_height - scaling));
	len[3] = (int)(0.5 * (var->map->res_height + scaling));
	var->map->sprites->starty = len[2];
	var->map->sprites->height = scaling;
	if (len[2] < 0)
		len[2] = 0;
	if (len[3] >= var->map->res_height)
		len[3] = var->map->res_height - 1;
	len[0] = (int)(0.5 * (var->map->res_width * (1 + proyect[0] / proyect[1])
		- scaling));
	len[1] = (int)(0.5 * (var->map->res_width * (1 + proyect[0] / proyect[1])
		+ scaling));
	var->map->sprites->startx = len[0];
	var->map->sprites->width = scaling;
	if (len[0] < 0)
		len[0] = 0;
	if (len[1] >= var->map->res_width)
		len[1] = var->map->res_width - 1;
}

t_sprites	duplicate_sprite(t_sprites src)
{
	t_sprites	dup;

	dup.x = src.x;
	dup.y = src.y;
	dup.dist = src.dist;
	return (dup);
}

void		replace_sprite(t_sprites *dst, t_sprites *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->dist = src->dist;
}
