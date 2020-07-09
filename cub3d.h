/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:16:50 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/09 11:20:41 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define READ_SIZE 50
# define CAM_VEL 0.1
# define ROT_VEL 0.01
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define EOPEN "Error opening file\n"
# define EPLAPOS "Starting position count not 1\n"
# define ENONCHR "Found symbol outside cub file standard\n"
# define ENOTCLO "Map not enclosed by walls\n"
# define EINFO "Wrong information in cub file parameters\n"
# define ETEXPATH "Texture file not found\n"
# define EARG "Wrong argument use\n"
# define EMLX "mlx init failure\n"
# define EWIN "mlx new window failure\n"

typedef struct		s_sprites
{
	double			x;
	double			y;
	double			dist;
}					t_sprites;

typedef struct		s_maps
{
	char			**val;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	int				height;
	int				res_height;
	int				res_width;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	int				*wall_lineheight;
	int				*wall_start;
	int				sprite_num;
	t_sprites		*sprites;
}					t_maps;

typedef struct		s_vars
{
	void			*win;
	void			*mlx;
	t_maps			*map;
	double			dirX;
	double			dirY;
	double			posX;
	double			posY;
	double			planeX;
	double			planeY;
	double			rayX;
	double			rayY;
	char			side;
	double			*ray_hit;
	double			*ray_distance;
	double			Lmove;
	double			Pmove;
	double			rot;
	int				must_save;
}					t_vars;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				endian;
	int				img_w;
	int				img_h;
}					t_imgs;

/*
**		ray_caster
*/
int					ray_caster(t_vars *var);
/*
**		hooks
*/
int					camera_update(t_vars *var);
/*
**		hooks_utils
*/
int					press_update(int keycode, t_vars *var);
int					release_update(int keycode, t_vars *var);
int					x_close(t_vars *var);
/*
**		pixel_handling
*/
void				put_pixel_wall_texture(t_imgs *im, int i, int j, t_vars *v);
void				put_pixel_ceilflo(t_imgs *im, int i, int j, unsigned int c);
void				set_pixel_limits(t_vars *var, double *len, int col);
/*
**		parse_cube_files_utils
*/
int					set_initial_camera_pos(t_vars *v, t_maps *m, int i, int j);
int					set_floor_ceil_color(t_maps *map, char *buff, int i);
void				set_mlx_texture_imgs(t_vars *var, t_imgs *img);
int					set_window_resolution(t_maps *map, char *buff, int i);
int					set_texture_paths(t_maps *map, char *buff, int i);
/*
**		error_check_utils
*/
char				**map_to_rectangle_by_sp(char **buff);
int					is_map_values_topoerr(char **val, int i, int j, int as);
int					is_cub_file_chr(int c);
void				error_exit(char *errstr);
/*
**		save_utils
*/
void				save_img(t_vars *var, void *img);
/*
**		sprite_caster
*/
void				sprite_caster_and_frame_to_win(t_vars *var, t_imgs *img);
/*
**		sprite_calc_utils
*/
void				calc_sprite_bounds(t_vars *v, int *len, double *pro);
t_sprites			duplicate_sprite(t_sprites src);
void				replace_sprite(t_sprites *dst, t_sprites *src);
#endif
