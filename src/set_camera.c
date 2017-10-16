/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 17:16:15 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 14:17:04 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	set_camera(t_camera *camera)
{
	camera->eye = vector_new3(0.0, 0.0, -5.0);
	camera->center = vector_new3(0.0, 0.0, 0.0);
	camera->up = vector_new3(0.0, 1.0, 0.0);
	camera->view = mtx_lookat(camera->eye, camera->center, camera->up);
	camera->projection = mtx_perspective(70.0,
			(float)WIN_W / (float)WIN_H, 1.0, 100.0);
}
