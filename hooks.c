/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:22:53 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/06 13:08:30 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	camera_rotation(int key, t_vars *var)
{
	double	temp;

	if (key == RIGHT)
	{
		temp = var->dirX;
		var->dirX = var->dirX * cos(0.01) + var->dirY * sin(0.01);
		var->dirY = -1 * temp * sin(0.01) + var->dirY * cos(0.01);
		temp = var->planeX;
		var->planeX = var->planeX * cos (0.01) + var->planeY * sin(0.01);
		var->planeY = -1 * temp * sin(0.01) + var->planeY * cos(0.01);
	}
	else if (key == LEFT)
	{
		temp = var->dirX;
		var->dirX = var->dirX * cos(0.01) - var->dirY * sin(0.01);
		var->dirY = temp * sin(0.01) + var->dirY * cos(0.01);
		temp = var->planeX;
		var->planeX = var->planeX * cos (0.01) - var->planeY * sin(0.01);
		var->planeY = temp * sin(0.01) + var->planeY * cos(0.01);
	}
}

static void	undo_update(int key, t_vars *var)
{
	var->posX -= (((key == UP) || (key == W) || (key == D))
		- ((key == DOWN) || (key == S) || (key == A))) * var->dirX * 0.1;
	var->posY -= (((key == UP) || (key == W) || (key == D))
		- ((key == DOWN) || (key == S) || (key == A))) * var->dirY * 0.1;
}

int			camera_update(int key, t_vars *var)
{
	if (key == ESC)
		return (x_close(var));
	if ((key == RIGHT) || (key == LEFT))
		camera_rotation(key, var);
	else if (key == UP || key == DOWN || key == S || key == W
		|| key == A || key == D)
	{
		var->posX += (((key == UP) || (key == W) || (key == D))
			- ((key == DOWN) || (key == S) || (key == A))) * var->dirX * 0.1;
		var->posY += (((key == UP) || (key == W) || (key == D))
			- ((key == DOWN) || (key == S) || (key == A))) * var->dirY * 0.1;
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

void		error_exit(char *errstr)
{
	ft_printf("Error\n%s", errstr);
	exit(1);
}
