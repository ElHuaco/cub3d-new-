/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_caster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:03:39 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/09 10:33:41 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void		sprite_caster_and_frame_to_win(t_vars *var, t_imgs *img)
{
	mlx_put_image_to_window(var->mlx, var->win, img[0].img, 0, 0);
	if (var->must_save == 1)
		save_img(var, img[0].img);
}
