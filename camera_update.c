/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:22:53 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/13 12:38:32 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		camera_rotation(t_vars *var, double angle)
{
	double temp;

	temp = var->dirx;
	var->dirx = var->dirx * cos(angle) - var->diry * sin(angle);
	var->diry = temp * sin(angle) + var->diry * cos(angle);
	temp = var->planex;
	var->planex = var->planex * cos(angle) - var->planey * sin(angle);
	var->planey = temp * sin(angle) + var->planey * cos(angle);
}

static void		both_move(t_vars *var)
{
	if (var->map->val[(int)var->posy]
		[(int)(var->posx + (var->dirx * var->pmove
		- var->diry * var->lmove) * 0.8)] != '1')
		var->posx += (var->dirx * var->pmove -
			var->diry * var->lmove) * 0.7;
	if (var->map->val[(int)(var->posy + (var->diry *
		var->pmove + var->dirx * var->lmove) * 0.8)]
		[(int)var->posx] != '1')
		var->posy += (var->diry * var->pmove +
			var->dirx * var->lmove) * 0.7;
}

int				camera_update(t_vars *var)
{
	if (!var->pmove || !var->lmove)
	{
		if (var->map->val[(int)(var->posy)]
			[(int)(var->posx + var->dirx
			* var->pmove * 1.1)] != '1')
			var->posx += var->dirx * var->pmove;
		if (var->map->val[(int)(var->posy + var->diry
			* var->pmove * 1.1)]
			[(int)var->posx] != '1')
			var->posy += var->diry * var->pmove;
		if (var->map->val[(int)var->posy]
			[(int)(var->posx - var->diry
			* var->lmove * 1.1)] != '1')
			var->posx -= var->diry * var->lmove;
		if (var->map->val[(int)(var->posy + var->dirx
			* var->lmove * 1.1)]
			[(int)var->posx] != '1')
			var->posy += var->dirx * var->lmove;
	}
	else
		both_move(var);
	if (var->rot != 0)
		camera_rotation(var, var->rot);
	return (0);
}
