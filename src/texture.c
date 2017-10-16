/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:52:59 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:00:58 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	update_texture_level(t_env *env)
{
	if (env->mode == 1)
	{
		env->texture_level += 0.05;
		if (env->texture_level > 1.0)
			env->texture_level = 1.0;
	}
	else
	{
		env->texture_level -= 0.05;
		if (env->texture_level < 0.0)
			env->texture_level = 0.0;
	}
}

void	load_textures(t_model *model)
{
	GLuint	texture_id;
	int		format;

	model->texture = (t_texture *)malloc(sizeof(t_texture));
	if (model->texture == NULL)
		exit_failure("malloc failed");
	if (model->flag == 1)
	{
		load_bmp("textures/kittens.bmp", model->texture);
		format = GL_BGRA;
	}
	else
	{
		load_bmp("textures/wood.bmp", model->texture);
		format = GL_BGR;
	}
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
			model->texture->width,
			model->texture->height,
			0, format, GL_UNSIGNED_BYTE, model->texture->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
