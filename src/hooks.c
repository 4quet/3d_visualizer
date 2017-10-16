/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 11:10:06 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:30:48 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

static void	handle_transformation_events(t_env *env)
{
	t_model *m;

	m = env->model;
	if (env->key[KEY_LEFT])
		m->translation = mtx_transf(m->translation, mtx_translate(0.1, 0, 0));
	if (env->key[KEY_RIGHT])
		m->translation = mtx_transf(m->translation, mtx_translate(-0.1, 0, 0));
	if (env->key[KEY_DOWN])
		m->translation = mtx_transf(m->translation, mtx_translate(0, -0.1, 0));
	if (env->key[KEY_UP])
		m->translation = mtx_transf(m->translation, mtx_translate(0, 0.1, 0));
	if (env->key[KEY_S])
		m->translation = mtx_transf(m->translation, mtx_translate(0, 0, -0.1));
	if (env->key[KEY_W])
		m->translation = mtx_transf(m->translation, mtx_translate(0, 0, 0.1));
	if (env->key[KEY_PLUS])
		m->scale = mtx_transf(m->scale, mtx_scale(1.05));
	if (env->key[KEY_MINUS])
		m->scale = mtx_transf(m->scale, mtx_scale(0.95));
	if (env->autospin == 1)
		m->rotation = mtx_transf(m->rotation,
			mtx_rotate(m->rotation_axis, DEG_TO_RAD(env->rotation_speed)));
}

int			loop_hook(t_env *env)
{
	if (env->key[KEY_ESC])
		exit_failure("ESCAPE");
	if (env->key[KEY_Z])
		env->rotation_speed += 0.1;
	if (env->key[KEY_X])
		env->rotation_speed -= 0.1;
	if (env->key[KEY_T])
		env->mode = -env->mode;
	if (env->key[KEY_R])
		env->autospin = -env->autospin;
	if (env->key[KEY_SPACE])
	{
		env->light_color++;
		if (env->light_color > 4)
			env->light_color = LIGHT_COLOR_WHITE;
	}
	handle_transformation_events(env);
	env->key[KEY_T] = 0;
	env->key[KEY_R] = 0;
	env->key[KEY_SPACE] = 0;
	expose_hook(env);
	return (0);
}

int			key_release(int keycode, t_env *env)
{
	env->key[keycode] = 0;
	return (0);
}

int			key_press(int keycode, t_env *env)
{
	env->key[keycode] = 1;
	return (0);
}

int			expose_hook(t_env *env)
{
	draw(env);
	update_texture_level(env);
	return (0);
}
