/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_first_frame.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 12:29:21 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/09 20:18:49 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		write_dib_header(int fd, int hex, t_vars *var)
{
	hex = 0x00000028;
	write(fd, &hex, 4);
	hex = var->map->res_width;
	write(fd, &hex, 4);
	hex = var->map->res_height;
	write(fd, &hex, 4);
	hex = 0x0001;
	write(fd, &hex, 2);
	hex = 0x0020;
	write(fd, &hex, 2);
	hex = 0x00000000;
	write(fd, &hex, 4);
	hex = var->map->res_height * var->map->res_width * 4;
	write(fd, &hex, 4);
	hex = 0x00000B13;
	write(fd, &hex, 4);
	hex = 0x00000B13;
	write(fd, &hex, 4);
	hex = 0x00000000;
	write(fd, &hex, 4);
	hex = 0x00000000;
	write(fd, &hex, 4);
}

static int		write_bmp_header(int fd, t_vars *var)
{
	int hex;

	hex = 0x4D42;
	write(fd, &hex, 2);
	hex = var->map->res_width * var->map->res_height * 4 + 54;
	write(fd, &hex, 4);
	hex = 0x00000;
	write(fd, &hex, 2);
	hex = 0x0000;
	write(fd, &hex, 2);
	hex = 0x00000036;
	write(fd, &hex, 4);
	write_dib_header(fd, hex, var);
	return (1);
}

static int		write_bmp_data(int fd, t_vars *var, t_imgs img)
{
	int					col;
	int					row;
	unsigned int		color;

	col = -1;
	while (++col < var->map->res_width)
	{
		row = -1;
		while (++row < var->map->res_height)
		{
			printf("pixel %d %d asignado\n", row, col);
			color = *(unsigned int*)(img.addr + row * img.ll
				+ col * (img.bpp / 8));
			if (write(fd, &color, 4) < 0)
				return (0);
		}
	}
	return (1);
}

void			screenshot(t_vars *var, t_imgs img)
{
	int fd;

	var->must_save = 0;
	if (!(fd = open("./screenshot.bmp", O_WRONLY | O_TRUNC | O_APPEND | O_CREAT
	, 0666)))
		error_exit(EWR);
	if (!(write_bmp_header(fd, var)))
		error_exit(EWR);
	if (!(write_bmp_data(fd, var, img)))
		error_exit(EWR);
	close(fd);
}
