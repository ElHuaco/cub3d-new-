/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:22:53 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/09 11:34:30 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	camera_rotation(t_vars *var, double angle)
{
	double	temp;

	temp = var->dirX;
	var->dirX = var->dirX * cos(angle) - var->dirY * sin(angle);
	var->dirY = temp * sin(angle) + var->dirY * cos(angle);
	temp = var->planeX;
	var->planeX = var->planeX * cos (angle) - var->planeY * sin(angle);
	var->planeY = temp * sin(angle) + var->planeY * cos(angle);
}

static void	ft_double_collision(t_vars *var)
{
	if (var->map->val[(int)var->posY]
		[(int)(var->posX + (var->dirX * var->Pmove
		- var->dirY * var->Lmove) * 0.8)]!= '1')
		var->posX += (var->dirX * var->Pmove -
		var->dirY * var->Lmove) * 0.7;
	if (var->map->val[(int)(var->posY + (var->dirY *
	var->Pmove + var->dirX * var->Lmove) * 0.8)][(int)var->posX]!= '1')
		var->posY += (var->dirY * var->Pmove +
		var->dirX * var->Lmove) * 0.7;
}

int		camera_update(t_vars *var)
{
//	if ((var->rot != 0) || (var->Pmove != 0) || (var->Lmove != 0))
//	printf("camera update variables status\n(rot, P, L): (%f, %f, %f)\n", var->rot, var->Pmove, var->Lmove);
	if (!var->Pmove || !var->Lmove)
	{
		if (var->map->val[(int)(var->posY)]
			[(int)(var->posX + var->dirX * var->Pmove * 1.1)] != '1')
			var->posX += var->dirX * var->Pmove;
		if (var->map->val[(int)(var->posY + var->dirY * var->Pmove * 1.1)]
			[(int)var->posX] != '1')
			var->posY += var->dirY * var->Pmove;
		if (var->map->val[(int)var->posY]
			[(int)(var->posX - var->dirY * var->Lmove * 1.1)] != '1')
			var->posX -= var->dirY * var->Lmove;
		if (var->map->val[(int)(var->posY + var->dirX * var->Lmove * 1.1)]
			[(int)var->posX]!= '1')
			var->posY += var->dirX * var->Lmove;
	}
	else
		ft_double_collision(var);
	if (var->rot != 0)
		camera_rotation(var, var->rot);
	return (0);
}











































