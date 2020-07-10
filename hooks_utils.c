/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 10:56:00 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/09 20:09:31 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			press_update(int key, t_vars *var)
{
	if (key == ESC)
		x_close(var);
	else if (key == W || key == UP)
		var->Pmove = CAM_VEL;
	else if (key == S || key == DOWN)
		var->Pmove = -1 * CAM_VEL;
	else if (key == A)
		var->Lmove = 0.5 * CAM_VEL;
	else if (key == D)
		var->Lmove = -0.5 * CAM_VEL;
	else if (key == RIGHT)
		var->rot = -1 * ROT_VEL;
	else if (key == LEFT)
		var->rot = ROT_VEL;
	return (0);
}

int			release_update(int key, t_vars *var)
{
	if (key == W || key == UP || key == S || key == DOWN)
		var->Pmove = 0;
	else if (key == A || key == D)
		var->Lmove = 0;
	else if (key == RIGHT || key == LEFT)
		var->rot = 0;
	return (0);
}

int			x_close(t_vars *var)
{
	free(var->map->north);
	free(var->map->south);
	free(var->map->west);
	free(var->map->east);
	free(var->map->sprite);
	full_free((void **)var->map->val, var->map->height);
	exit(0);
	return (0);
}
