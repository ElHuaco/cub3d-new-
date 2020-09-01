/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 10:56:00 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/09/01 14:04:44 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			press_update(int key, t_vars *var)
{
	if (key == ESC)
		x_close(var);
	else if (key == W || key == UP)
		var->pmove = CAM_VEL;
	else if (key == S || key == DOWN)
		var->pmove = -1 * CAM_VEL;
	else if (key == A)
		var->lmove = -0.5 * CAM_VEL;
	else if (key == D)
		var->lmove = 0.5 * CAM_VEL;
	else if (key == RIGHT)
		var->rot = ROT_VEL;
	else if (key == LEFT)
		var->rot = -1 * ROT_VEL;
	return (0);
}

int			release_update(int key, t_vars *var)
{
	if (key == W || key == UP || key == S || key == DOWN)
		var->pmove = 0;
	else if (key == A || key == D)
		var->lmove = 0;
	else if (key == RIGHT || key == LEFT)
		var->rot = 0;
	return (0);
}

int			x_close(t_vars *var)
{
	int	i;

	i = -1;
	while (++i < 6)
		mlx_destroy_image(var->win, var->img[i].img);
	free(var->img);
	full_free((void **)var->map->side, 5);
	full_free((void **)var->map->val, var->map->height);
	exit(0);
	return (0);
}
