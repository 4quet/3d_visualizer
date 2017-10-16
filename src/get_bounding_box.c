/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bounding_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:53:18 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 14:06:10 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_bounding_box(t_model *model)
{
	size_t n;

	n = 0;
	while (n < model->size)
	{
		model->bounding_box[0] = MIN(model->bounding_box[0],
				model->vertices[n]);
		model->bounding_box[1] = MAX(model->bounding_box[1],
				model->vertices[n]);
		model->bounding_box[2] = MIN(model->bounding_box[2],
				model->vertices[n + 1]);
		model->bounding_box[3] = MAX(model->bounding_box[3],
				model->vertices[n + 1]);
		model->bounding_box[4] = MIN(model->bounding_box[4],
				model->vertices[n + 2]);
		model->bounding_box[5] = MAX(model->bounding_box[5],
				model->vertices[n + 2]);
		n += 3;
	}
	model->center = vector_new3(
			(model->bounding_box[0] + model->bounding_box[1]) / 2,
			(model->bounding_box[2] + model->bounding_box[3]) / 2,
			(model->bounding_box[4] + model->bounding_box[5]) / 2);
}
