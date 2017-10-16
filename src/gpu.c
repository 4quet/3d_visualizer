/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:49:09 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 14:13:09 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	bind_vbos(t_env *env)
{
	env->vertices_vbo = 0;
	env->normals_vbo = 0;
	env->colors_vbo = 0;
	env->uvs_vbo = 0;
	glGenBuffers(1, &env->vertices_vbo);
	glGenBuffers(1, &env->normals_vbo);
	glGenBuffers(1, &env->colors_vbo);
	glGenBuffers(1, &env->uvs_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, env->vertices_vbo);
	glBufferData(GL_ARRAY_BUFFER, env->model->size * sizeof(float),
			env->model->vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, env->normals_vbo);
	glBufferData(GL_ARRAY_BUFFER, env->model->size * sizeof(float),
			env->model->normals, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, env->colors_vbo);
	glBufferData(GL_ARRAY_BUFFER, env->model->size * sizeof(float),
			env->model->colors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, env->uvs_vbo);
	glBufferData(GL_ARRAY_BUFFER, (env->model->size * 3 / 2) * sizeof(float),
			env->model->uv, GL_STATIC_DRAW);
}

void	bind_vao(t_env *env)
{
	env->vao = 0;
	glGenVertexArrays(1, &env->vao);
	glBindVertexArray(env->vao);
	glBindBuffer(GL_ARRAY_BUFFER, env->vertices_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, env->normals_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, env->colors_vbo);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, env->uvs_vbo);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
}
