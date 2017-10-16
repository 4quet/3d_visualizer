/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:53:49 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 14:12:18 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_normals(t_model *model)
{
	size_t		i;
	size_t		j;
	t_vector	*normal;

	if ((model->normals = (float *)malloc(sizeof(float) * model->size)) == NULL)
		exit_failure("malloc failed");
	i = 0;
	while (i < model->size)
	{
		normal = triangle_face_normal(
				vector_new3(model->vertices[i], model->vertices[i + 1],
							model->vertices[i + 2]),
				vector_new3(model->vertices[i + 3], model->vertices[i + 4],
							model->vertices[i + 5]),
				vector_new3(model->vertices[i + 6], model->vertices[i + 7],
							model->vertices[i + 8]));
		j = 0;
		while (j < 9)
		{
			model->normals[i + j] = normal->value[j % 3];
			j++;
		}
		i += 9;
		mtx_free(&normal);
	}
}
