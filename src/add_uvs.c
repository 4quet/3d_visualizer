/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_uvs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 12:48:32 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 14:04:29 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	set_uv(t_model *model, size_t u, size_t v)
{
	static size_t	j = 0;

	model->uv[j] = model->vertices[u];
	model->uv[j + 1] = model->vertices[v];
	j += 2;
}

void		add_uvs(t_model *model)
{
	size_t		i;
	size_t		uv_size;
	t_vector	*v;

	uv_size = (model->size / 3) * 2;
	model->uv = (float *)malloc(sizeof(float) * uv_size);
	if (model->uv == NULL)
		exit_failure("malloc failed");
	i = 0;
	while (i < model->size)
	{
		v = vector_new3(model->normals[i],
				model->normals[i + 1], model->normals[i + 2]);
		vector_normalize(v);
		if ((v->value[2] < 0.1 && v->value[2] > -0.1) &&
				v->value[1] < 0.1 && v->value[1] > -0.1)
			set_uv(model, i + 2, i + 1);
		else if ((v->value[2] < 0.1 && v->value[2] > -0.1) &&
				v->value[0] < 0.1 && v->value[0] > -0.1)
			set_uv(model, i + 2, i);
		else
			set_uv(model, i, i + 1);
		i += 3;
		mtx_free(&v);
	}
}
