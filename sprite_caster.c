/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_caster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:39:48 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/09/02 12:29:13 by alejandro        ###   ########.fr       */
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
					pow(var->posx - j - 0.5, 2) + pow(var->posy - i - 0.5, 2);
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

static void	put_sprite_img(t_vars *v, int *l, double *p, t_imgs *im)
{
	char	*dst;
	char	*src;
	int		s[2];
	int		i[2];

	i[0] = l[0] - 1;
	while (++(*(i + 0)) < l[1] - 1)
	{
		s[0] = (i[0] - v->map->sprites->startx) * im[5].img_w
			/ v->map->sprites->width;
		if ((p[1] > 0) && (i[0] > 0) && (i[0] < v->map->res_width)
			&& (p[1] < v->ray_distance[*(i + 0)]))
		{
			i[1] = l[2] - 1;
			while (++(*(i + 1)) < l[3] - 1)
			{
				s[1] = (i[1] - v->map->sprites->starty) * im[5].img_h
					/ v->map->sprites->height;
				dst = im[0].addr + i[1] * im[0].ll + i[0] * (im[0].bpp / 8);
				src = im[5].addr + s[1] * im[5].ll + s[0] * (im[5].bpp / 8);
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
		var->map->sprites[i].x -= var->posx;
		var->map->sprites[i].y -= var->posy;
		*((double *)len + 4) = 1.0
			/ (var->planex * var->diry - var->planey * var->dirx);
		proyect[0] = (var->diry * var->map->sprites[i].x
			- var->dirx * var->map->sprites[i].y) * *((double *)len + 4);
		proyect[1] = (-1 * var->planey * var->map->sprites[i].x
			+ var->planex * var->map->sprites[i].y) * *((double *)len + 4);
		set_sprite_limits(var, len, proyect);
		put_sprite_img(var, len, proyect, img);
	}
	mlx_put_image_to_window(var->mlx, var->win, img[0].img, 0, 0);
	if (var->must_save == 1)
		screenshot(var, img[0]);
	free(var->map->sprites);
}
