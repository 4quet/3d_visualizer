/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 17:17:36 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 17:11:39 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	load_model(t_model *model, char *obj_file)
{
	float	target;

	if (strcmp(&obj_file[strlen(obj_file) - 6], "42.obj") == 0)
		model->flag = 1;
	else
		model->flag = 0;
	if ((model->bounding_box = (float *)malloc(sizeof(float) * 6)) == NULL)
		exit_failure("malloc failed");
	ft_bzero(model->bounding_box, sizeof(float) * 6);
	read_obj(obj_file, model);
	get_normals(model);
	get_colors(model);
	add_uvs(model);
	model->translation = mtx_identity(4);
	model->rotation = mtx_identity(4);
	model->scale = mtx_identity(4);
	model->rotation_axis = vector_new3(ROT_AXIS_X, ROT_AXIS_Y, ROT_AXIS_Z);
	target = 0.0;
	while (target > model->bounding_box[4])
	{
		model->scale = mtx_transf(model->scale, mtx_scale(0.95));
		target -= 0.90;
	}
}
