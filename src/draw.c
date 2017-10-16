/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:54:02 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:02:15 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	set_light_color(t_env *env)
{
	t_vector	*color;
	GLuint		loc;

	if (env->light_color == LIGHT_COLOR_RED)
		color = vector_new3(1.0, 0.7, 0.7);
	else if (env->light_color == LIGHT_COLOR_GREEN)
		color = vector_new3(0.7, 1.0, 0.7);
	else if (env->light_color == LIGHT_COLOR_BLUE)
		color = vector_new3(0.7, 0.7, 1.0);
	else
		color = vector_new3(1.0, 1.0, 1.0);
	loc = glGetUniformLocation(env->shader, "lightColor");
	glUniform3f(loc, color->value[0], color->value[1], color->value[2]);
	mtx_free(&color);
}

void		draw(t_env *env)
{
	t_mtx	*model;
	GLuint	texture_level_location;

	model = mtx_translate(-env->model->center->value[0],
							-env->model->center->value[1],
							-env->model->center->value[2]);
	model = mtx_transf(model, mtx_copy(env->model->scale));
	model = mtx_transf(model, mtx_copy(env->model->rotation));
	model = mtx_transf(model, mtx_copy(env->model->translation));
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(env->shader);
	set_light_color(env);
	set_uniform_mtx(env->shader, "model", model->value);
	set_uniform_mtx(env->shader, "view", env->camera->view->value);
	set_uniform_mtx(env->shader, "projection", env->camera->projection->value);
	texture_level_location = glGetUniformLocation(env->shader, "textureLevel");
	glUniform1f(texture_level_location, env->texture_level);
	glBindVertexArray(env->vao);
	glDrawArrays(GL_TRIANGLES, 0, env->model->size / 3.0);
	glBindVertexArray(0);
	glUseProgram(0);
	mlx_opengl_swap_buffers(env->win);
	mtx_free(&model);
}
