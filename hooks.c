/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:22:53 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/07 13:32:41 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	camera_rotation(t_vars *var, double angle)
{
	double	temp;

	temp = var->dirX;
	var->dirX = var->dirX * cos(angle) + var->dirY * sin(angle);
	var->dirY = -1 * temp * sin(angle) + var->dirY * cos(angle);
	temp = var->planeX;
	var->planeX = var->planeX * cos (angle) + var->planeY * sin(angle);
	var->planeY = -1 * temp * sin(angle) + var->planeY * cos(angle);
}

static void	undo_update(int key, t_vars *var)
{
	var->posX -= (((key == UP) || (key == W))
		- ((key == DOWN) || (key == S))) * var->dirX * CAM_VEL;
	var->posY -= (((key == UP) || (key == W))
		- ((key == DOWN) || (key == S))) * var->dirY * CAM_VEL;
}

int			camera_update(int key, t_vars *var)
{
	if (key == ESC)
		return (x_close(var));
	if ((key == RIGHT) || (key == LEFT))
		camera_rotation(var, ROT_ANGLE * ((key == RIGHT) - (key == LEFT)));
	else if (key == UP || key == DOWN || key == S || key == W)
	{
		var->posX += (((key == UP) || (key == W))
			- ((key == DOWN) || (key == S))) * var->dirX * CAM_VEL;
		var->posY += (((key == UP) || (key == W))
			- ((key == DOWN) || (key == S))) * var->dirY * CAM_VEL;
	}
	else if ((key == A) || (key == D))
	{
		camera_rotation(var, -1 * M_PI_2 * ((key == A) - (key == D)));
		camera_update(W, var);
		camera_rotation(var, M_PI_2 * ((key == A) - (key == D)));
	}
	if (((var->map->val[(int)var->posY][(int)var->posX] == '0')
		|| var->map->val[(int)var->posY][(int)var->posX] == '2')
		&& (var->map->val[(int)(var->posY + 0.1)][(int)(var->posX + 0.1)] != '1')
		&& (var->map->val[(int)(var->posY - 0.1)][(int)(var->posX + 0.1)] != '1')
		&& (var->map->val[(int)(var->posY + 0.1)][(int)(var->posX - 0.1)] != '1')
		&& (var->map->val[(int)(var->posY - 0.1)][(int)(var->posX - 0.1)] != '1'))
		ray_caster(var);
	else
		undo_update(key, var);
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


