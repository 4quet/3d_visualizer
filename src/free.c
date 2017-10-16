/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:47:20 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 14:06:27 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	free_model(t_model *model)
{
	mtx_free(&model->scale);
	mtx_free(&model->scale);
	mtx_free(&model->rotation);
	mtx_free(&model->translation);
	mtx_free(&model->rotation_axis);
	mtx_free(&model->center);
	free(model->texture->data);
	free(model->texture);
	free(model->bounding_box);
	free(model->vertices);
	free(model->normals);
	free(model->colors);
	free(model->uv);
}

static void	free_camera(t_camera *camera)
{
	mtx_free(&camera->eye);
	mtx_free(&camera->center);
	mtx_free(&camera->up);
	mtx_free(&camera->view);
	mtx_free(&camera->projection);
}

void		free_program(t_env *env)
{
	free_model(env->model);
	free_camera(env->camera);
	glDeleteBuffers(1, &env->vertices_vbo);
	glDeleteBuffers(1, &env->normals_vbo);
	glDeleteBuffers(1, &env->colors_vbo);
	glDeleteBuffers(1, &env->uvs_vbo);
	glDeleteProgram(env->shader);
	mlx_destroy_window(env->mlx, env->win);
}
