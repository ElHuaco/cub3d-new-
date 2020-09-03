/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:16:50 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/09/03 13:35:42 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_opengl_20191021/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <fcntl.h>

# define READ_SIZE 50
# define CAM_VEL 0.15
# define ROT_VEL 0.03
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
# define EWR "Error writing file\n"
# define EPLAPOS "Starting position count not 1\n"
# define ENONCHR "Found symbol outside cub file standard in map values\n"
# define ENOTCLO "Map not enclosed by walls\n"
# define EINFOC "Wrong information in C or F color parameters\n"
# define EINFOR "Wrong information in window resolution\n"
# define EINFOT "Wrong information in texture path. Must be in same folder\n"
# define EINFO "Wrong cub file info: arrived at non-descriptive char\n"
# define ETEXPATH "Texture file not found\n"
# define EARG "Wrong argument use\n"
# define EMLX "mlx init failure\n"
# define EWIN "mlx new window failure\n"

typedef struct		s_sprites
{
	double			x;
	double			y;
	double			dist;
	int				startx;
	int				starty;
	int				width;
	int				height;
}					t_sprites;

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

typedef struct		s_maps
{
	char			**val;
	char			**side;
	char			*sprite;
	int				height;
	int				res_height;
	int				res_width;
	unsigned int	floor_col;
	unsigned int	ceil_col;
	int				is_floor_color_set;
	int				is_ceil_color_set;
	int				*wall_lineheight;
	int				*wall_start;
	int				sprite_num;
	t_imgs			*img;
	t_sprites		*sprites;
}					t_maps;

typedef struct		s_vars
{
	void			*win;
	void			*mlx;
	t_maps			*map;
	t_imgs			*img;
	double			dirx;
	double			diry;
	double			posx;
	double			posy;
	double			planex;
	double			planey;
	double			rayx;
	double			rayy;
	char			side;
	double			*ray_hit;
	double			*ray_distance;
	double			lmove;
	double			pmove;
	double			rot;
	int				must_save;
}					t_vars;
/*
**		ray_caster
*/
int					ray_caster(t_vars *var);
/*
**		camera_update
*/
int					camera_update(t_vars *var);
/*
**		hooks
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
**		parse_cube_file_utils
*/
int					set_initial_camera_pos(t_vars *v, t_maps *m, int i, int j);
int					set_floor_ceil_color(t_maps *map, char *buff, int i);
void				set_image_textures(t_vars *var);
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
**		screenshot_first_frame
*/
void				screenshot(t_vars *var, t_imgs img);
/*
**		sprite_caster
*/
void				sprite_caster_and_frame_to_win(t_vars *var, t_imgs *img);
/*
**		sprite_calc_utils
*/
void				set_sprite_limits(t_vars *v, int *len, double *pro);
t_sprites			duplicate_sprite(t_sprites src);
void				replace_sprite(t_sprites *dst, t_sprites *src);
#endif
