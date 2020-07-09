/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_caster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:39:48 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/09 12:13:37 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_map_sprites(t_vars *var)
{
	t_sprites	*sprites;
	int			n;
	int			i;
	int			j;

	n = 0;
	i = -1;
	while (++i < var->map->height)
	{
		j = -1;
		while (var->map->val[i][++j])
		{
			if (var->map->val[i][j] == '2')
				n++;
		}
	}
	sprites = malloc(sizeof(struct s_sprites) * n);
	var->map->sprites = sprites;
	return (n);
}

static void	find_sprite_pos_and_dist(t_vars *var)
{
	int		i;
	int		j;
	int		k;

	k = -1;
	i = -1;
	while (++i < var->map->height)
	{
		j = -1;
		while (var->map->val[i][++j])
		{
			if (var->map->val[i][j] == '2')
			{
				var->map->sprites[++k].x = j + 0.5;
				var->map->sprites[k].y = i + 0.5;
				var->map->sprites[k].dist =
					pow(var->posX - j - 0.5, 2) + pow(var->posY - i - 0.5, 2);
			}
		}
	}
}

static void	sort_sprites_by_distance(t_vars *var)
{
	int			i;
	int			j;
	t_sprites	temp;

	i = -1;
	while (++i < var->map->sprite_num)
	{
		j = -1;
		while (++j < var->map->sprite_num)
		{
			if ((var->map->sprites[j].dist > var->map->sprites[i].dist)
				&& (j > i))
			{ 
				temp = duplicate_sprite(var->map->sprites[i]);
				replace_sprite(var->map->sprites + i,
					var->map->sprites + j);
				replace_sprite(var->map->sprites + j, &temp);
			}
		}
	}
}

static void	put_sprite_img(t_vars *v, int *l, double *p, t_imgs *i)
{
	char	*dst;
	char	*src;
	int		s[2];
	int		c;
	int		r;

	c = l[0] - 1;
	while (++c < l[1] - 1)
	{
		s[0] = (c - l[0]) * i[5].img_w * fabs(p[1] / v->map->res_height);
	 	if ((p[1] > 0) && (c > 0) && (c < v->map->res_width)
				&& (p[1] < v->ray_distance[c]))
		{
			r = l[2] - 1;
			while (++r < l[3])
			{
				s[1] = (r - l[2]) * i[5].img_h
				* fabs(p[1] / v->map->res_height);
				dst = i[0].addr + r * i[0].ll + c * (i[0].bpp / 8);
				src = i[5].addr + s[1] * i[5].ll + s[0] * (i[5].bpp / 8);
				if (*(unsigned int *)src != 0)
					*(unsigned int *)dst = *(unsigned int *)src;
			}
		}
	}
}

void		sprite_caster_and_frame_to_win(t_vars *var, t_imgs *img)
{
	int		i;
	double	proyect[2];
	int		len[5];

	var->map->sprite_num = count_map_sprites(var);
	find_sprite_pos_and_dist(var);
	sort_sprites_by_distance(var);
	i = -1;
	while (++i < var->map->sprite_num)
	{
		var->map->sprites[i].x -= var->posX;
		var->map->sprites[i].y -= var->posY;
		len[4] = 1.0 / (var->planeX * var->dirY - var->planeY * var->dirX);
		proyect[0] = (var->dirY * var->map->sprites[i].x
			- var->dirX * var->map->sprites[i].y) * len[4];
		proyect[1] = (-1 * var->planeY * var->map->sprites[i].x
			+ var->planeX * var->map->sprites[i].y) * len[4];
		if (fabs(proyect[1]) > 10e-7)
		{
			calc_sprite_bounds(var, len, proyect);
			put_sprite_img(var, len, proyect, img);
		}
	}
	mlx_put_image_to_window(var->mlx, var->win, img[0].img, 0, 0);
	if (var->must_save == 1)
		save_img(var, img[0].img);
}

