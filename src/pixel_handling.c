/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:25:39 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/09 20:14:01 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_wall_texture(t_imgs *img, int i, int j, t_vars *var)
{
	char	*dst;
	int		side;
	int		corresp_tex_coord[2];

	side = 1 * (var->side == 'n') + 2 * (var->side == 's')
		+ 3 * (var->side == 'w') + 4 * (var->side == 'e');
	if ((side == 2) || (side == 4))
		corresp_tex_coord[0] = img[side].img_w * (1.0 - var->ray_hit[i]);
	else
		corresp_tex_coord[0] = img[side].img_w * var->ray_hit[i];
	corresp_tex_coord[1] = ((j - var->map->wall_start[i])
		* img[side].img_h / var->map->wall_lineheight[i])
		& (img[side].img_h - 1);
	dst = img[0].addr + j * img[0].ll + i * (img[0].bpp / 8);
	*(unsigned int*)dst = *(unsigned int*)(img[side].addr
		+ corresp_tex_coord[1] * img[side].ll
		+ corresp_tex_coord[0] * (img[side].bpp / 8));
}

void	put_pixel_ceilflo(t_imgs *img, int i, int j, unsigned int color)
{
	char	*dst;

	dst = img[0].addr + j * img[0].ll + i * (img[0].bpp / 8);
	*(unsigned int *)dst = color;
}

void	set_pixel_limits(t_vars *var, double *len, int col)
{
	len[2] = (int)((0.5 * var->map->res_height) * (1.0 - 1.0 / len[0]));
	len[1] = (int)((0.5 * var->map->res_height) * (1.0 + 1.0 / len[0]));
	var->map->wall_start[col] = len[2];
	var->map->wall_lineheight[col] = (int)(var->map->res_height / len[0]);
	if (len[2] < 0)
		len[2] = 0;
	if (len[1] >= var->map->res_height)
		len[1] = var->map->res_height - 1;
}
