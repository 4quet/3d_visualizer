/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:48:40 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 16:57:39 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		exit_failure(char const *message)
{
	printf("scop: %s\n", message);
	exit(EXIT_FAILURE);
}

static void	set_minilibx_opengl(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_opengl_window(env->mlx, WIN_W, WIN_H, "scop");
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_hook(env->win, 3, (1L << 1), key_release, env);
	mlx_hook(env->win, 2, (1L << 0), key_press, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

static void	init_env(t_env *env)
{
	env->autospin = 1;
	env->rotation_speed = 0.5;
	env->mode = -1;
	env->texture_level = 0;
	env->light_color = 1;
}

int			main(int argc, char **argv)
{
	t_env		env;
	t_model		model;
	t_camera	camera;

	if (argc < 2)
	{
		printf("usage: ./scop file.obj\n");
		return (EXIT_FAILURE);
	}
	set_minilibx_opengl(&env);
	load_model(&model, argv[1]);
	load_textures(&model);
	set_camera(&camera);
	init_env(&env);
	env.model = &model;
	env.camera = &camera;
	load_shaders(&env);
	bind_vbos(&env);
	bind_vao(&env);
	mlx_loop(env.mlx);
	free_program(&env);
	return (0);
}
