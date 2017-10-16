/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:46:38 by lfourque          #+#    #+#             */
/*   Updated: 2016/11/15 13:04:25 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "mlx.h"
# include "mlx_opengl.h"
# include "libft.h"
# include "libmath.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <OpenGL/gl3.h>
# include <stdio.h>

# define KEY_S				1
# define KEY_Z				6
# define KEY_X				7
# define KEY_W				13
# define KEY_R				15
# define KEY_T				17
# define KEY_SPACE			49
# define KEY_ESC			53
# define KEY_PLUS			69
# define KEY_MINUS			78
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_UP				126

# define LIGHT_COLOR_WHITE	1
# define LIGHT_COLOR_RED	2
# define LIGHT_COLOR_GREEN	3
# define LIGHT_COLOR_BLUE	4

# define ROT_AXIS_X			0.0
# define ROT_AXIS_Y			1.0
# define ROT_AXIS_Z			0.0

# define WIN_W				1200.0
# define WIN_H				800.0

# define DEG_TO_RAD(DEG) 	(DEG * M_PI / 180.0)
# define MIN(X, Y) 			(((X) < (Y)) ? (X) : (Y))
# define MAX(X, Y) 			(((X) > (Y)) ? (X) : (Y))

typedef struct		s_texture
{
	size_t			width;
	size_t			height;
	unsigned char	*data;
}					t_texture;

typedef struct		s_model
{
	size_t			size;
	float			*vertices;
	float			*normals;
	float			*colors;
	float			*uv;
	float			*bounding_box;
	t_vector		*center;
	t_vector		*rotation_axis;
	t_texture		*texture;
	t_mtx			*translation;
	t_mtx			*rotation;
	t_mtx			*scale;
	int				flag;
}					t_model;

typedef struct		s_camera
{
	t_vector		*eye;
	t_vector		*center;
	t_vector		*up;
	t_mtx			*view;
	t_mtx			*projection;
}					t_camera;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_model			*model;
	t_camera		*camera;
	GLuint			shader;
	GLuint			vertices_vbo;
	GLuint			normals_vbo;
	GLuint			colors_vbo;
	GLuint			uvs_vbo;
	GLuint			vao;
	float			rotation_speed;
	float			texture_level;
	int				key[300];
	int				autospin;
	int				light_color;
	int				mode;
}					t_env;

/*
**	MAIN.C
*/
void				exit_failure(char const *message);

/*
**	LOAD_MODEL.C
*/
void				load_model(t_model *model, char *obj_file);

/*
**	SET_CAMERA.C
*/
void				set_camera(t_camera *camera);

/*
**	HOOKS.C
*/
int					expose_hook(t_env *env);
int					loop_hook(t_env *env);
int					key_press(int keycode, t_env *env);
int					key_release(int keycode, t_env *env);

/*
**	DRAW.C
*/
void				draw(t_env *env);

/*
**	SHADERS.C
*/
void				load_shaders(t_env *env);

/*
**	READ_OBJ.C
*/
void				read_obj(char const *path, t_model *model);

/*
**	LOAD_BMP.C
*/
void				load_bmp(char const *path, t_texture *texture);

/*
**	GET_NORMALS.C
*/
void				get_normals(t_model *model);

/*
**	GET_COLORS.C
*/
void				get_colors(t_model *model);

/*
**	ADD_UVS.C
*/
void				add_uvs(t_model *model);

/*
**	GET_FACE_VERTICES.C
*/
void				get_face_vertices(float *vertices, char *line, float *v);

/*
**	SET_UNIFORM.C
*/
void				set_uniform_mtx(GLuint shader, char const *name,
									float *mtx_value);

/*
**	FREE.C
*/
void				free_program(t_env *env);

/*
**	GPU.C
*/
void				bind_vbos(t_env *env);
void				bind_vao(t_env *env);

/*
**	TEXTURE.C
*/
void				load_textures(t_model *model);
void				update_texture_level(t_env *env);

/*
**	GET_BOUNDING_BOX.C
*/
void				get_bounding_box(t_model *model);

#endif
